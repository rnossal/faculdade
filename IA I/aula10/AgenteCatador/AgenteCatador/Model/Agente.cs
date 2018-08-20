using AgenteCatador.General;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Threading;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Definição de uma entidade de agente.
	/// </summary>
	public class Agente : Entidade
	{
		#region Atributos privados.
		/// <summary>
		/// Quantidade de vezes que não encontrou nada ao redor.
		/// </summary>
		public int _naoEncontrouNada;
		#endregion Atributos privados.

		#region Atributos públicos.
		/// <summary>
		/// Quantidade de lixo seco que o agente poderá carregar.
		/// </summary>
		public int CapacidadeMaximaLixoSeco { get; set; }
		/// <summary>
		/// Quantidade de lixo orgânico que o agente poderá carregar.
		/// </summary>
		public int CapacidadeMaximaLixoOrganico { get; set; }
		/// <summary>
		/// Lixos que estão dentro do saco de lixo seco.
		/// </summary>
		public ObservableCollection<Lixo> SacoLixoSeco { get; set; }
		/// <summary>
		/// Lixos que estão dentro do saco de lixo orgânico.
		/// </summary>
		public ObservableCollection<Lixo> SacoLixoOrganico { get; set; }
		/// <summary>
		/// Número de identificação do agente.
		/// </summary>
		public int Numero { get; set; }
		#endregion Atributos públicos.

		/// <summary>
		/// Agente com informações básicas do ambiente.
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		/// <param name="numero">Numero de identificação.</param>
		public Agente(Coordenadas coordenadas, int numero) : base(coordenadas)
		{
			Numero = numero;
			SacoLixoSeco = new ObservableCollection<Lixo>();
			SacoLixoOrganico = new ObservableCollection<Lixo>();
			_naoEncontrouNada = 0;
			CapacidadeMaximaLixoOrganico = 2;
			CapacidadeMaximaLixoSeco = 2;
		}

		/// <summary>
		/// Verifica se o saco de lixo orgânico está cheio.
		/// </summary>
		/// <returns>Status de resposta.</returns>
		public bool SacoLixoOrganicoEstaCheio()
		{
			return SacoLixoOrganico.Count >= CapacidadeMaximaLixoOrganico;
		}

		/// <summary>
		/// Verifica se o saco de lixo seco está cheio.
		/// </summary>
		/// <returns>Status de resposta.</returns>
		public bool SacoLixoSecoEstaCheio()
		{
			return SacoLixoSeco.Count >= CapacidadeMaximaLixoSeco;
		}

		/// <summary>
		/// Procura a lixeira mais próxima a partir do tipo definido.
		/// </summary>
		/// <param name="tipo">Tipo de lixeira a ser localizada.</param>
		/// <param name="desconsiderar">Lixeiras que o agente visitou, estão cheias e pode desconsiderar conforme a definição.</param>
		/// <returns>Lixeira mais próxima encontrada.</returns>
		public Lixeira ProcuraLixeiraProxima(TipoLixo tipo, List<Lixeira> desconsiderar = null)
		{
			if (desconsiderar == null)
				desconsiderar = new List<Lixeira>();

			List<Lixeira> lixeirasFind = Ambiente.Lixeiras.Except(desconsiderar).ToList().FindAll(l => l.Tipo == tipo);

			lixeirasFind.Sort((l1, l2) => Geral.DistanciaPontos(this, l1).CompareTo(Geral.DistanciaPontos(this, l2)));

			return lixeirasFind.FirstOrDefault();
		}

		/// <summary>
		/// Olha aos arredores do agente em busca de entidades para ele trabalhar.
		/// </summary>
		/// <returns>Lista de entidades encontradas.</returns>
		public List<Entidade> OlhaArredores()
		{
			List<Entidade> entidadesEncontradas = new List<Entidade>();

			foreach (Direcoes valor in Enum.GetValues(typeof(Direcoes)))
			{
				Coordenadas coordenadas = Geral.GetCoordenadasPorDirecao(this.Coordenadas, valor);
				Entidade entidade = Ambiente.GetEntidade(coordenadas);

				if (entidade is Agente || entidade is Lixeira || entidade is Lixo)
				{
					entidadesEncontradas.Add(entidade);
				}
				else if (valor == Direcoes.NENHUMA && entidade is Multiplo)
				{
					entidadesEncontradas.AddRange((entidade as Multiplo).Entidades.Except(new List<Entidade> { this }));
				}

				Thread.Sleep(MainWindow.VelocidadeAgentes);
			}

			return entidadesEncontradas;
		}

		/// <summary>
		/// Vai até a coordenada informada passo a passo.
		/// </summary>
		/// <param name="coordenadas">Coordenadas para onde o agente deverá ir.</param>
		/// <returns>Se conseguiu ou não se mover até o local desejado.</returns>
		public bool VaiAte(Coordenadas coordenadas)
		{
			int desviou = 0;
			int andou = 0;
			int tentativas = 0;
			while ((this.Coordenadas.X != coordenadas.X || this.Coordenadas.Y != coordenadas.Y))
			{
				if (tentativas > 3)
					return false;
				Coordenadas canditata = new Coordenadas();

				if (((Ambiente.GetEntidade(coordenadas) is Agente || Ambiente.GetEntidade(coordenadas) is Lixeira)) && EstaDiretamenteAoLado(coordenadas))
				{
					break;
				}

				int distanciaX = coordenadas.X - this.Coordenadas.X;
				int distanciaY = coordenadas.Y - this.Coordenadas.Y;

				if (Math.Abs(distanciaX) > Math.Abs(distanciaY))
				{
					if (coordenadas.X > this.Coordenadas.X)
					{
						canditata.X = this.Coordenadas.X + 1;
					}
					else
					{
						canditata.X = this.Coordenadas.X - 1;
					}

					canditata.Y = this.Coordenadas.Y;
				}
				else
				{
					if (coordenadas.Y > this.Coordenadas.Y)
					{
						canditata.Y = this.Coordenadas.Y + 1;
					}
					else
					{
						canditata.Y = this.Coordenadas.Y - 1;
					}

					canditata.X = this.Coordenadas.X;
				}

				if (Geral.PodeCaminhar(canditata))
				{
					Ambiente.MoveEntidade(canditata, this);

					if (andou > 2)
					{
						desviou = 0;
					}
					andou++;
				}
				else
				{
					if (desviou < 2)
					{
						Desvia(canditata, coordenadas);
						desviou++;
					}
					else
					{
						MoveAleatoriamente();
						MoveAleatoriamente();
						desviou = 0;
					}

					tentativas++;
					andou = 0;
				}

				Thread.Sleep(MainWindow.VelocidadeAgentes);
			}

			return true;
		}

		/// <summary>
		/// Pega lixo em determinada coordenada.
		/// </summary>
		/// <param name="coordenadas">Coordenadas de onde o lixo está.</param>
		/// <returns>Se conseguiu pegar o lixo ou não.</returns>
		public bool PegaLixo(Coordenadas coordenadas)
		{
			Entidade entidade = Ambiente.GetEntidade(coordenadas);
			Lixo lixo = null;

			if (entidade is Multiplo)
			{
				lixo = (entidade as Multiplo).Entidades.Find(e => e is Lixo) as Lixo;
			}
			else if (entidade is Lixo)
			{
				lixo = entidade as Lixo;
			}

			if (lixo != null && (lixo.Tipo == TipoLixo.ORGANICO && !SacoLixoOrganicoEstaCheio() || lixo.Tipo == TipoLixo.SECO && !SacoLixoSecoEstaCheio()))
			{
				bool sucesso = VaiAte(coordenadas);

				Multiplo multiplo = Ambiente.GetEntidade(this.Coordenadas) as Multiplo;

				if (multiplo != null && sucesso)
				{
					sucesso = false;

					lixo = multiplo.Entidades.Find(e => e is Lixo) as Lixo;

					if (lixo.Tipo == TipoLixo.ORGANICO && !SacoLixoOrganicoEstaCheio())
					{
						this.SacoLixoOrganico.Add(lixo);
						multiplo.Entidades.Remove(lixo);
						sucesso = true;
					}
					else if (lixo.Tipo == TipoLixo.SECO && !SacoLixoSecoEstaCheio())
					{
						this.SacoLixoSeco.Add(lixo);
						multiplo.Entidades.Remove(lixo);
						sucesso = true;
					}

					if (multiplo.Entidades.Count <= 1)
					{
						Ambiente.AtualizaEntidade(this);
					}
					else
					{
						Ambiente.AtualizaEntidade(multiplo);
					}
				}

				return sucesso;
			}

			return false;
		}

		public bool DespejaLixo(Coordenadas coordenadas)
		{
			Lixeira lixeira = Ambiente.GetEntidade(coordenadas) as Lixeira;
			ObservableCollection<Lixo> sacoLixo = null;

			if (lixeira.Tipo == TipoLixo.ORGANICO)
			{
				sacoLixo = this.SacoLixoOrganico;
			}
			else if (lixeira.Tipo == TipoLixo.SECO)
			{
				sacoLixo = this.SacoLixoSeco;
			}

			if (lixeira != null && sacoLixo != null)
			{
				VaiAte(coordenadas);

				if (EstaDiretamenteAoLado(coordenadas))
				{
					while (sacoLixo.Count != 0 && !lixeira.EstaCheia())
					{
						Lixo lixo = sacoLixo.First();
						if (lixo != null)
						{
							lixeira.Lixos.Add(lixo);
							sacoLixo.Remove(lixo);
						}
					}

					Ambiente.AtualizaEntidade(lixeira);
					Ambiente.AtualizaEntidade(this);

					if (sacoLixo.Count == 0)
					{
						return true;
					}
				}
			}

			return false;
		}

		/// <summary>
		/// Move o agente aleatoriamente em uma posição adjacente  ou na linha ou na coluna do agente.
		/// </summary>
		/// <param name="adjacente">Se ele deve se mover somente na linha ou coluna adjacente.</param>
		/// <returns>Retorno se conseguiu se mover ou não.</returns>
		public bool MoveAleatoriamente(bool adjacente = true)
		{
			Coordenadas coordenadas = new Coordenadas { X = this.Coordenadas.X, Y = this.Coordenadas.Y };
			List<Direcoes> direcoes = new List<Direcoes>
			{
				Direcoes.CIMA,
				Direcoes.BAIXO,
				Direcoes.ESQUERDA,
				Direcoes.DIREITA,
			};

			while (!Geral.PodeCaminhar(coordenadas) && !Geral.EstaTrancado(this.Coordenadas))
			{
				if (adjacente)
				{
					direcoes.Shuffle();

					foreach (Direcoes direcao in direcoes)
					{
						coordenadas = Geral.GetCoordenadasPorDirecao(this.Coordenadas, direcao);

						if (Geral.PodeCaminhar(coordenadas))
							break;
					}
				}
				else
				{
					// Se for zero move no x, se não, no y.
					if (Geral.Random.Next(2) == 0)
					{
						coordenadas.X = Geral.Random.Next(Ambiente.Colunas);
						coordenadas.Y = this.Coordenadas.Y;
					}
					else
					{
						coordenadas.X = this.Coordenadas.X;
						coordenadas.Y = Geral.Random.Next(Ambiente.Linhas);
					}
				}
			}

			return VaiAte(coordenadas);
		}

		/// <summary>
		/// Junção de todas as regras na ordem para o agente tomar as decições necessárias no ambiente.
		/// </summary>
		public void Age()
		{
			MainWindow.LogMessage($"Agente {Numero} selecionado para agir.");
			if (SacoLixoOrganicoEstaCheio() || SacoLixoSecoEstaCheio())
			{
				TipoLixo tipoLixo = SacoLixoOrganicoEstaCheio() ? TipoLixo.ORGANICO : TipoLixo.SECO;

				MainWindow.LogMessage($"Saco de {Geral.GetDescricaoEnum(tipoLixo).ToLower()} está cheio. Vai até a lixeira mais próxima descartar.");

				Lixeira lixeiraMaisProxima = ProcuraLixeiraProxima(tipoLixo);
				List<Lixeira> desconsiderar = new List<Lixeira>();

				bool pronto = false;
				while (!pronto && lixeiraMaisProxima != null)
				{
					pronto = DespejaLixo(lixeiraMaisProxima.Coordenadas);
					desconsiderar.Add(lixeiraMaisProxima);
					lixeiraMaisProxima = ProcuraLixeiraProxima(tipoLixo, desconsiderar);
				}

				if (!pronto)
					MainWindow.LogMessage($"Não conseguiu despejar todo o lixo necessário. Irá tentar novamente no próximo ciclo.");
			}
			else
			{
				MainWindow.LogMessage("Olha em volta...");
				List<Entidade> aoRedor = OlhaArredores();

				List<Entidade> lixosParaColetar = new List<Entidade>();
				if (!SacoLixoOrganicoEstaCheio())
				{
					lixosParaColetar.AddRange(aoRedor.FindAll(e => e is Lixo && (e as Lixo).Tipo == TipoLixo.ORGANICO));
				}
				if (!SacoLixoSecoEstaCheio())
				{
					lixosParaColetar.AddRange(aoRedor.FindAll(e => e is Lixo && (e as Lixo).Tipo == TipoLixo.SECO));
				}

				MainWindow.LogMessage($"Possui lixo em volta para pegar? {(lixosParaColetar.Count > 0 ? "Sim" : "Não")}");
				if (lixosParaColetar.Count > 0)
				{
					MainWindow.LogMessage("Vai pegar o primeiro lixo que encontrou.");
					bool sucesso = PegaLixo(lixosParaColetar.First().Coordenadas);
					if (!sucesso)
					{
						MainWindow.LogMessage("Não conseguiu pegar o lixo. Irá tentar novamente no próximo ciclo.");
					}
				}
				else
				{
					_naoEncontrouNada++;
					bool sucesso = false;

					if (_naoEncontrouNada < 3)
					{
						MainWindow.LogMessage("Não encontrou nada, vai andar aleatoriamente nos limites dele.");
						sucesso = MoveAleatoriamente(true);
					}
					else
					{
						MainWindow.LogMessage("Não encontrou pela terceira vez, vai andar aleatoriamente por uma linha ou coluna.");
						sucesso = MoveAleatoriamente(false);
						_naoEncontrouNada = 0;
					}

					if (!sucesso)
						MainWindow.LogMessage("Não conseguiu se mover para o ponto desejado, provavelmente porque estava trancado.");
				}
			}
		}

		/// <summary>
		/// Verifica se uma coordenada é diretamente do lado de outra.
		/// </summary>
		/// <param name="pontoFinal">Ponto a ser verificado a coordenada.</param>
		/// <returns></returns>
		private bool EstaDiretamenteAoLado(Coordenadas pontoFinal)
		{

			if (Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.CIMA).X == pontoFinal.X && Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.CIMA).Y == pontoFinal.Y ||
				Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.BAIXO).X == pontoFinal.X && Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.BAIXO).Y == pontoFinal.Y ||
				Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.ESQUERDA).X == pontoFinal.X && Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.ESQUERDA).Y == pontoFinal.Y ||
				Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.DIREITA).X == pontoFinal.X && Geral.GetCoordenadasPorDirecao(this.Coordenadas, Direcoes.DIREITA).Y == pontoFinal.Y)
			{
				return true;
			}

			return false;
		}

		/// <summary>
		/// Desvia de uma entidade no caminho.
		/// </summary>
		/// <param name="pontoObstaculo">Coordenadas da entidade a ser desviada.</param>
		/// <param name="pontoFinal">Coordenadas do ponto em que ele tentará chegar com esse desvio (otimiza o melhor lugar para ele escolher onde desviar).</param>
		public void Desvia(Coordenadas pontoObstaculo, Coordenadas pontoFinal)
		{
			Direcoes direcaoIr; // A direção que ele está indo quando encontrou o obstáculo.
			Direcoes direcaoDesvio; // Direção que ele deverá ir para desviar.
			Direcoes direcaoChecagem; // Direção que ele deverá checar se pode caminhar para se livrar do obstáculo.
			Direcoes[] sentidoObstaculo = GetSentidoAtePonto(pontoObstaculo); // Em que sentidos o obstáculo está do agente.
			Direcoes[] sentidoCaminho = GetSentidoAtePonto(pontoFinal); // Em que sentido está o lugar ao qual o agente quer chegar.

			#region Vê para onde ele sempre tentará chegar.
			if (Math.Abs(pontoFinal.X - this.Coordenadas.X) > Math.Abs(pontoFinal.Y - this.Coordenadas.Y))
				direcaoIr = pontoFinal.X > this.Coordenadas.X ? Direcoes.DIREITA : Direcoes.ESQUERDA;
			else
				direcaoIr = pontoFinal.Y > this.Coordenadas.Y ? Direcoes.BAIXO : Direcoes.CIMA;
			#endregion Vê para onde ele sempre tentará chegar.

			direcaoChecagem = direcaoIr;

			#region Vê o foco para tentar desviar.
			if (direcaoIr == Direcoes.ESQUERDA || direcaoIr == Direcoes.DIREITA)
				direcaoDesvio = sentidoCaminho[1] == Direcoes.BAIXO ? Direcoes.BAIXO : Direcoes.CIMA;
			else
				direcaoDesvio = sentidoCaminho[0] == Direcoes.ESQUERDA ? Direcoes.ESQUERDA : Direcoes.DIREITA;
			#endregion Vê o foco para tentar desviar.

			int qtdMudancasDirecao = 0;
			int demaisCaminho = 0;
			bool semFim = false;
			while (!Desviou(sentidoObstaculo, pontoObstaculo, pontoFinal) && !semFim)
			{
				Coordenadas coordenadasDesvio = Geral.GetCoordenadasPorDirecao(this.Coordenadas, direcaoDesvio);
				Coordenadas coordenadasChecagem = Geral.GetCoordenadasPorDirecao(this.Coordenadas, direcaoChecagem);
				Coordenadas coordenadasDestino = Geral.GetCoordenadasPorDirecao(this.Coordenadas, direcaoIr);

				if (Geral.PodeCaminhar(coordenadasDestino))
				{
					VaiAte(coordenadasDestino);
				}
				else if (Geral.PodeCaminhar(coordenadasChecagem) && demaisCaminho < 3)
				{
					demaisCaminho++;
					VaiAte(coordenadasChecagem);
				}
				else if (Geral.PodeCaminhar(coordenadasDesvio) && !Geral.PodeCaminhar(coordenadasChecagem) && demaisCaminho < 3)
				{
					demaisCaminho++;
					VaiAte(coordenadasDesvio);
				}
				else if ((!Geral.PodeCaminhar(coordenadasDesvio) && !Geral.PodeCaminhar(coordenadasChecagem)) || demaisCaminho >= 3)
				{
					if (demaisCaminho >= 3)
						demaisCaminho = 0;
					
					if (direcaoDesvio == direcaoIr && qtdMudancasDirecao >= 3)
						break;

					if (direcaoDesvio == Direcoes.BAIXO)
					{
						direcaoDesvio = Direcoes.ESQUERDA;
						direcaoChecagem = Direcoes.BAIXO;
						qtdMudancasDirecao++;
					}
					else if (direcaoDesvio == Direcoes.ESQUERDA)
					{
						direcaoDesvio = Direcoes.CIMA;
						direcaoChecagem = Direcoes.ESQUERDA;
						qtdMudancasDirecao++;
					}
					else if (direcaoDesvio == Direcoes.CIMA)
					{
						direcaoDesvio = Direcoes.DIREITA;
						direcaoChecagem = Direcoes.CIMA;
						qtdMudancasDirecao++;
					}
					else if (direcaoDesvio == Direcoes.DIREITA)
					{
						direcaoDesvio = Direcoes.BAIXO;
						direcaoChecagem = Direcoes.DIREITA;
						qtdMudancasDirecao++;
					}
				}
				else
				{
					semFim = true;
				}
			}
		}

		private bool Desviou(Direcoes[] sentidoObstaculo, Coordenadas pontoObstaculo, Coordenadas pontoFinal)
		{
			Direcoes[] direcoesChecar = GetSentidoAtePonto(pontoObstaculo);
			Direcoes[] pontoFinalDirecoes = GetSentidoAtePonto(pontoFinal);

			if (EstaDiretamenteAoLado(pontoFinal))
				return true;

			if (sentidoObstaculo[0] != Direcoes.NENHUMA)
			{
				if (direcoesChecar[0] == Direcoes.ESQUERDA && sentidoObstaculo[0] == Direcoes.DIREITA)
				{
					return true;
				}
				else if (direcoesChecar[0] == Direcoes.DIREITA && sentidoObstaculo[0] == Direcoes.ESQUERDA)
				{
					return true;
				}
				else if (pontoFinalDirecoes[0] == GetSentidoAtePonto(this.Coordenadas)[0])
				{
					return true;
				}
			}
			else
			{
				if (direcoesChecar[1] == Direcoes.CIMA && sentidoObstaculo[1] == Direcoes.BAIXO)
				{
					return true;
				}
				else if (direcoesChecar[1] == Direcoes.BAIXO && sentidoObstaculo[1] == Direcoes.CIMA)
				{
					return true;
				}
				else if (pontoFinalDirecoes[1] == GetSentidoAtePonto(this.Coordenadas)[1])
				{
					return true;
				}
			}
			return false;
		}

		/// <summary>
		/// Retorna o sentido até o ponto que o agente precisa tomar.
		/// </summary>
		/// <param name="pontoFinal">Ponto a ser verificado o sentido.</param>
		/// <returns>Array de duas posições onde a primeira é a direção de x e a segunda é a direção de y.</returns>
		private Direcoes[] GetSentidoAtePonto(Coordenadas pontoFinal)
		{
			Direcoes sentidoX;
			Direcoes sentidoY;

			#region Decide se o agente precisará ir para direita ou esquerda para chegar.
			if (pontoFinal.X > this.Coordenadas.X)
				sentidoX = Direcoes.DIREITA;
			else if (pontoFinal.X < this.Coordenadas.X)
				sentidoX = Direcoes.ESQUERDA;
			else
				sentidoX = Direcoes.NENHUMA;
			#endregion Decide se o agente precisará ir para direita ou esquerda para chegar.

			#region Decide se o agente precisará ir para cima ou para baixo para chegar.
			if (pontoFinal.Y > this.Coordenadas.Y)
				sentidoY = Direcoes.BAIXO;
			else if (pontoFinal.Y < this.Coordenadas.Y)
				sentidoY = Direcoes.CIMA;
			else
				sentidoY = Direcoes.NENHUMA;
			#endregion Decide se o agente precisará ir para cima ou para baixo para chegar.

			return new Direcoes[] { sentidoX, sentidoY };
		}
	}
}
