using AgenteCatador.General;
using System.Collections.Generic;

namespace AgenteCatador.Model
{
	public static class Ambiente
	{
		#region Atributos privados.
		/// <summary>
		/// Quantidade interna de linhas que o ambiente possui.
		/// </summary>
		private static int _linhas;
		/// <summary>
		/// Quantidade interna de colunas que o ambiente possui.
		/// </summary>
		private static int _colunas;
		/// <summary>
		/// Matriz interna do ambiente representado.
		/// </summary>
		private static Entidade[,] _ambiente;
		/// <summary>
		/// Todas entidades internas juntas.
		/// </summary>
		public static List<Entidade> _entidades;
		/// <summary>
		/// Entidades internas de agentes no ambiente.
		/// </summary>
		public static List<Agente> _agentes;
		/// <summary>
		/// Entidades internas de lixeiras no ambiente.
		/// </summary>
		public static List<Lixeira> _lixeiras;
		/// <summary>
		/// Entidades internas de lixos no ambiente.
		/// </summary>
		public static List<Lixo> _lixos;
		#endregion Atributos privados.

		#region Atributos públicos.
		/// <summary>
		/// Quantidade de linhas que o ambiente possui.
		/// </summary>
		public static int Linhas
		{
			get
			{
				return _linhas;
			}
		}
		/// <summary>
		/// Quantidade de colunas que o ambiente possui.
		/// </summary>
		public static int Colunas
		{
			get
			{
				return _linhas;
			}
		}
		/// <summary>
		/// Todas entidades juntas.
		/// </summary>
		public static List<Entidade> Entidades
		{
			get
			{
				return _entidades;
			}
		}
		/// <summary>
		/// Entidades internas de no ambiente.
		/// </summary>
		public static List<Agente> Agentes
		{
			get
			{
				return _agentes;
			}
		}
		/// <summary>
		/// Entidades de lixeiras no ambiente.
		/// </summary>
		public static List<Lixeira> Lixeiras
		{
			get
			{
				return _lixeiras;
			}
		}
		/// <summary>
		/// Entidades de lixos no ambiente.
		/// </summary>
		public static List<Lixo> Lixos
		{
			get
			{
				return _lixos;
			}
		}
		/// <summary>
		/// Delegate indicando quando o ambiente for modificado.
		/// </summary>
		/// <param name="entidade">Entidade que causou a mudança.</param>
		/// <param name="coordenadas">Posição x da mudança.</param>
		public delegate void AmbienteChanged(Entidade entidade, Coordenadas coordenadas);
		/// <summary>
		/// Evento disparado ao ambiente ter mudado.
		/// </summary>
		public static event AmbienteChanged AmbienteChange;
		#endregion Atributos públicos.

		/// <summary>
		/// Inicia um ambiente vazio.
		/// </summary>
		/// <param name="linhas">Número de linhas do ambiente.</param>
		/// <param name="colunas">Número de colunas do ambiente.</param>
		public static void Criar(int linhas, int colunas)
		{
			AmbienteChange = null;
			_linhas = linhas;
			_colunas = colunas;
			_ambiente = new Entidade[linhas, colunas];
			_entidades = new List<Entidade>();
			_agentes = new List<Agente>();
			_lixeiras = new List<Lixeira>();
			_lixos = new List<Lixo>();
		}

		/// <summary>
		/// Procura todas as coordenadas que estão livres no ambiente.
		/// </summary>
		/// <returns>Lista com as coordenadas livres.</returns>
		public static List<Coordenadas> GetCoordenadasLivres()
		{
			List<Coordenadas> livres = new List<Coordenadas>();

			for (int y = 0; y < _linhas; y++)
			{
				for (int x = 0; x < _colunas; x++)
				{
					Entidade entidade = _ambiente[y, x];

					if (entidade == null)
					{
						livres.Add(new Coordenadas { X = x, Y = y });
					}
				}
			}

			return livres;
		}

		/// <summary>
		/// Pega uma entidade na posição desejada.
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		/// <returns>Entidade encontrada.</returns>
		public static Entidade GetEntidade(Coordenadas coordenadas)
		{
			if (Geral.EstaLimite(coordenadas))
				return _ambiente[coordenadas.Y, coordenadas.X];

			return null;
		}

		/// <summary>
		/// Coloca uma entidade na posição definida.
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		/// <param name="entidade">Entidade que será colocada.</param>
		public static void SetEntidade(Coordenadas coordenadas, Entidade entidade)
		{
			Entidade pos = _ambiente[coordenadas.Y, coordenadas.X];

			if (pos != null)
			{
				_entidades.Remove(pos);
				_agentes.Remove(pos as Agente);
				_lixeiras.Remove(pos as Lixeira);
				_lixos.Remove(pos as Lixo);
			}

			_ambiente[coordenadas.Y, coordenadas.X] = entidade;

			if (entidade != null)
			{
				entidade.Coordenadas.X = coordenadas.X;
				entidade.Coordenadas.Y = coordenadas.Y;

				if (entidade is Agente)
				{
					_agentes.Add(entidade as Agente);
				}
				else if (entidade is Lixeira)
				{
					_lixeiras.Add(entidade as Lixeira);
				}
				else if (entidade is Lixo)
				{
					_lixos.Add(entidade as Lixo);
				}

				_entidades.Add(entidade);
			}

			AmbienteChange?.Invoke(entidade, coordenadas);
		}

		/// <summary>
		/// Move uma entidade para outro ponto qualquer. Se Já houver uma entidade, as duas se transformam em uma entidade múltipla que contém as duas.
		/// Se houver só um item nessa lista depois de mover, esse item se toma o lugar da entidade múltipla.
		/// </summary>
		/// <param name="destino">Posição de destino no ambiente.</param>
		/// <param name="entidade">Entidade que será movida.</param>
		public static void MoveEntidade(Coordenadas destino, Entidade entidade)
		{
			Entidade orig = _ambiente[entidade.Coordenadas.Y, entidade.Coordenadas.X];

			if (orig is Multiplo)
			{
				(orig as Multiplo).Entidades.Remove(entidade);

				if ((orig as Multiplo).Entidades.Count == 1)
				{
					_ambiente[entidade.Coordenadas.Y, entidade.Coordenadas.X] = (orig as Multiplo).Entidades[0];
				}
				else if ((orig as Multiplo).Entidades.Count == 0)
				{
					_ambiente[entidade.Coordenadas.Y, entidade.Coordenadas.X] = null;
				}
			}
			else
			{
				_ambiente[entidade.Coordenadas.Y, entidade.Coordenadas.X] = null;
			}

			AmbienteChange?.Invoke(_ambiente[entidade.Coordenadas.Y, entidade.Coordenadas.X], new Coordenadas { X = entidade.Coordenadas.X, Y = entidade.Coordenadas.Y });

			entidade.Coordenadas = destino;

			Entidade dest = _ambiente[destino.Y, destino.X];

			if (dest != null)
			{
				Multiplo multiplo;

				if (dest is Multiplo)
				{
					multiplo = dest as Multiplo;
					multiplo.Entidades.Add(entidade);
				}
				else
				{
					multiplo = new Multiplo(destino);
					multiplo.Entidades.Add(_ambiente[destino.Y, destino.X]);
					multiplo.Entidades.Add(entidade);
				}

				_ambiente[destino.Y, destino.X] = multiplo;
			}
			else
			{
				_ambiente[destino.Y, destino.X] = entidade;
			}

			AmbienteChange?.Invoke(_ambiente[destino.Y, destino.X], destino);
		}

		/// <summary>
		/// Força a entidade a atualizar a tela.
		/// </summary>
		/// <param name="entidade">Entidade que irá atualizar.</param>
		public static void AtualizaEntidade(Entidade entidade)
		{
			AmbienteChange?.Invoke(entidade, entidade.Coordenadas);
		}

		/// <summary>
		/// Verifica se ainda possui algum lixo no chão
		/// </summary>
		/// <returns>Se ainda possui lixos ou não.</returns>
		public static bool TemLixoChao()
		{
			for (int y = 0; y < _linhas; y++)
			{
				for (int x = 0; x < _colunas; x++)
				{
					Entidade entidade = _ambiente[y, x];

					if (entidade is Lixo)
					{
						return true;
					}
					else if (entidade is Multiplo)
					{
						foreach(Entidade ent in (entidade as Multiplo).Entidades)
						{
							if (ent is Lixo)
							{
								return true;
							}
						}
					}
				}
			}

			return false;
		}
	}
}
