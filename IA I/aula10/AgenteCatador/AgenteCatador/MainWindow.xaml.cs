using AgenteCatador.General;
using AgenteCatador.Model;
using AgenteCatador.UCs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace AgenteCatador
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		/// <summary>
		/// Thread responsável por rodar a simulação em loop até terminar.
		/// </summary>
		private Thread _executor;
		/// <summary>
		/// Variável que guarda se o usuário quer que a aplicação rode automaticamente ou por enter.
		/// </summary>
		bool _ciclosAutomaticos;
		/// <summary>
		/// Estado de se pode rodar a simulação ou não.
		/// </summary>
		bool _simula;
		/// <summary>
		/// Usado no caso do enter onde um novo ciclo só pode ser executado se o anterior tiver terminado completamente.
		/// </summary>
		bool _podeExecutar;
		/// <summary>
		/// Quantidade de ciclos que a simulação atingiu.
		/// </summary>
		int _ciclos;
		/// <summary>
		/// Velocidade de movimento dos agentes no ambiente.
		/// </summary>
		public static int VelocidadeAgentes;

		public MainWindow()
		{
			InitializeComponent();
			_ciclosAutomaticos = false;
			_simula = false;
			_podeExecutar = true;
			_ciclos = 1;
			VelocidadeAgentes = 100;
			velocidadeAgentes.Text = VelocidadeAgentes.ToString();
		}

		/// <summary>
		/// Método que vai realmente rodar a lógica dos agentes.
		/// </summary>
		private void ExecutorRun()
		{
				while (_simula && _ciclosAutomaticos)
				{
					RodaCiclo();
				}
		}

		/// <summary>
		/// Roda um ciclo e incrementa a contagem.
		/// </summary>
		private void RodaCiclo()
		{
			if (_simula)
			{
				MainWindow.LogMessage($"Ciclo {_ciclos}.");

				foreach (Agente ag in Ambiente.Agentes)
				{
					ag.Age();

					if (!Ambiente.TemLixoChao())
					{
						_simula = false;
						MainWindow.LogMessage("Simulação terminada!");
						MainWindow.LogMessage($"\n{_ciclos} ciclos foram necessários para que todos os lixos fossem recolhidos.");
						_ciclos = 0;
						break;
					}
				}

				if (Ambiente.TemLixoChao())
					MainWindow.LogMessage($"Fim do ciclo {_ciclos}.\n");

				_ciclos++;
			}
			_podeExecutar = true;
		}

		#region Métodos para gerenciamento do ambiente.
		/// <summary>
		/// Aloca as entidades no ambiente conforme a quantidade requerida.
		/// </summary>
		/// <param name="qtdAgentes">Quantidade de agentes que estarão no ambiente.</param>
		/// <param name="qtdLixoOrganico">Quantidade de lixos orgânicos que estarão no ambiente.</param>
		/// <param name="qtdLixeiraOrganico">Quantidade de lixeiras de lixo orgânico que estarão no ambiente.</param>
		/// <param name="qtdLixoSeco">Quantidade de lixos secos que estarão no ambiente.</param>
		/// <param name="qtdLixeiraSeco">Quantidade de lixeiras de lixo seco que estarão no ambiente.</param>
		/// <returns>Se conseguiu alocar tudo com sucesso.</returns>
		private bool AlocaEntidadesAmbiente(int qtdAgentes, int qtdLixoOrganico, int qtdLixeiraOrganico, int qtdLixoSeco, int qtdLixeiraSeco)
		{

			for (int i = 0; i < qtdLixeiraOrganico; i++)
			{
				Lixeira lixeira = AlocaEntidadeLugarSeguro(Entidades.LIXEIRA_ORGANICO) as Lixeira;
				if (lixeira == null)
					return false;
			}

			for (int i = 0; i < qtdLixeiraSeco; i++)
			{
				Lixeira lixeira = AlocaEntidadeLugarSeguro(Entidades.LIXEIRA_SECO) as Lixeira;
				if (lixeira == null)
					return false;
			}

			for (int i = 0; i < qtdLixoOrganico; i++)
			{
				Lixo lixo = AlocaEntidadeLugarSeguro(Entidades.LIXO_ORGANICO) as Lixo;
				if (lixo == null)
					return false;
			}

			for (int i = 0; i < qtdLixoSeco; i++)
			{
				Lixo lixo = AlocaEntidadeLugarSeguro(Entidades.LIXO_SECO) as Lixo;
				if (lixo == null)
					return false;
			}

			List<Lixeira> lixeirasOrganico = Ambiente.Lixeiras.FindAll(l => l.Tipo == TipoLixo.ORGANICO);
			List<Lixeira> lixeirasSeco = Ambiente.Lixeiras.FindAll(l => l.Tipo == TipoLixo.SECO);
			while (qtdLixoOrganico != 0)
			{

				foreach (Lixeira lixeira in lixeirasOrganico)
				{
					lixeira.CapacidadeMaxima++;

					if (--qtdLixoOrganico == 0)
						break;
				}
			}
			while (qtdLixoSeco != 0)
			{

				foreach (Lixeira lixeira in lixeirasSeco)
				{
					lixeira.CapacidadeMaxima++;

					if (--qtdLixoSeco == 0)
						break;
				}
			}

			for (int i = 0; i < qtdAgentes; i++)
			{
				Agente agente;

				agente = AlocaEntidadeLugarSeguro(Entidades.AGENTE) as Agente;
				if (agente == null)
					return false;
				agente.CapacidadeMaximaLixoOrganico = 2;
				agente.CapacidadeMaximaLixoSeco = 2;
			}

			return true;
		}

		/// <summary>
		/// Cria uma entidade em um lugar livre no ambiente.
		/// </summary>
		/// <param name="entidadeTipo">Tipo de entidade para tentar criar.</param>
		/// <returns>Entidade criada.</returns>
		private Entidade AlocaEntidadeLugarSeguro(Entidades entidadeTipo)
		{
			List<Coordenadas> livres = Ambiente.GetCoordenadasLivres();
			livres.Shuffle();

			foreach (Coordenadas coordenadas in livres)
			{
				if (entidadeTipo == Entidades.LIXEIRA_ORGANICO || entidadeTipo == Entidades.LIXEIRA_SECO)
				{
					if (Geral.EstaLivreArredores(coordenadas))
					{
						Ambiente.SetEntidade(coordenadas, new Lixeira(coordenadas, (entidadeTipo == Entidades.LIXEIRA_ORGANICO ? TipoLixo.ORGANICO : TipoLixo.SECO)));
						return Ambiente.GetEntidade(coordenadas);
					}
				}
				else if (!Geral.EstaTrancado(coordenadas))
				{
					if (entidadeTipo == Entidades.AGENTE)
					{
						Ambiente.SetEntidade(coordenadas, new Agente(coordenadas, Ambiente.Agentes.Count + 1));
						return Ambiente.GetEntidade(coordenadas);
					}
					else if (entidadeTipo == Entidades.LIXO_ORGANICO || entidadeTipo == Entidades.LIXO_SECO)
					{
						Ambiente.SetEntidade(coordenadas, new Lixo(coordenadas, (entidadeTipo == Entidades.LIXO_ORGANICO ? TipoLixo.ORGANICO : TipoLixo.SECO)));
						return Ambiente.GetEntidade(coordenadas);
					}
				}
			}

			return null;
		}
		#endregion Métodos para gerenciamento do ambiente.

		#region Métodos exclusivos para controle de interface.
		/// <summary>
		/// Exibe uma mensagem na coluna de log da tela.
		/// </summary>
		/// <param name="msg">Mensagem a ser exibida.</param>
		public static void LogMessage(string msg)
		{
			Application.Current.Dispatcher.Invoke(() =>
			{
				MainWindow main = ((MainWindow)Application.Current.MainWindow);

				main.logger.AppendText($"{msg}\n");
				main.logger.ScrollToEnd();
			});
		}
		/// <summary>
		/// Limpa o console de log.
		/// </summary>
		private void LimpaLog()
		{
			logger.Clear();
		}
		/// <summary>
		/// Vê o que teve de mudança e limpa da tela entidades que não estão mais naquela posição do ambiente.
		/// </summary>
		private void LimpaEntidades()
		{
			List<EntidadeUC> entidadesUC = GetEntidades(e => e.Tipo != Entidades.NENHUM);

			foreach (EntidadeUC entidadeUC in entidadesUC)
			{
				Entidade entidade = Ambiente.GetEntidade(entidadeUC.Coordenadas);
				if (entidade == null)
				{
					entidadeUC.Tipo = Entidades.NENHUM;
				}
			}
		}

		/// <summary>
		/// Pega os objetos instanciados dentro da matriz e exibe na posição respectiva da interface.
		/// </summary>
		private void AtualizaEntidades()
		{
			LimpaEntidades();

			for (int y = 0; y < Ambiente.Linhas; y++)
			{
				for (int x = 0; x < Ambiente.Colunas; x++)
				{
					Entidade entidade = Ambiente.GetEntidade(new Coordenadas { X = x, Y = y });

					AtualizaEntidade(entidade, new Coordenadas { X = x, Y = y });
				}
			}
		}

		/// <summary>
		/// Atualiza uma única entidade na posição respectiva na interface.
		/// </summary>
		/// <param name="entidade">Entidade para atualizar na interface.</param>
		/// <param name="coordenadas">Posição na interface.</param>
		private void AtualizaEntidade(Entidade entidade, Coordenadas coordenadas)
		{
			if (entidade is Lixo)
			{
				EntidadeUC entidadeUc = GetEntidade(coordenadas);
				Lixo lixo = entidade as Lixo;

				if (lixo.Tipo == TipoLixo.SECO)
					entidadeUc.Tipo = Entidades.LIXO_SECO;
				else if (lixo.Tipo == TipoLixo.ORGANICO)
					entidadeUc.Tipo = Entidades.LIXO_ORGANICO;
			}
			else if (entidade is Lixeira)
			{
				EntidadeUC entidadeUc = GetEntidade(coordenadas);
				Lixeira lixeira = entidade as Lixeira;

				if (lixeira.Tipo == TipoLixo.SECO)
				{
					entidadeUc.Tipo = Entidades.LIXEIRA_SECO;
					entidadeUc.QtdLixoSeco = lixeira.Lixos.Count;
					entidadeUc.CapacidadeMaximaLixoSeco = lixeira.CapacidadeMaxima;
				}
				else if (lixeira.Tipo == TipoLixo.ORGANICO)
				{
					entidadeUc.Tipo = Entidades.LIXEIRA_ORGANICO;
					entidadeUc.QtdLixoOrganico = lixeira.Lixos.Count;
					entidadeUc.CapacidadeMaximaLixoOrganico = lixeira.CapacidadeMaxima;
				}
			}
			else if (entidade is Agente)
			{
				EntidadeUC entidadeUc = GetEntidade(coordenadas);
				Agente agente = entidade as Agente;

				entidadeUc.Tipo = Entidades.AGENTE;
				entidadeUc.QtdLixoSeco = agente.SacoLixoSeco.Count;
				entidadeUc.CapacidadeMaximaLixoSeco = agente.CapacidadeMaximaLixoSeco;
				entidadeUc.QtdLixoOrganico = agente.SacoLixoOrganico.Count;
				entidadeUc.CapacidadeMaximaLixoOrganico = agente.CapacidadeMaximaLixoOrganico;
				entidadeUc.NumeroAgente = agente.Numero;
			}
			else if (entidade is Multiplo)
			{
				EntidadeUC entidadeUc = GetEntidade(coordenadas);

				entidadeUc.EntidadesMultiplo = (entidade as Multiplo).Entidades;
				entidadeUc.Tipo = Entidades.MULTIPLO;
			}
			else
			{
				EntidadeUC entidadeUc = GetEntidade(coordenadas);

				entidadeUc.Tipo = Entidades.NENHUM;
			}
		}

		/// <summary>
		/// Desenha a interface do ambiente e seus elementos.
		/// </summary>
		private void DesenhaAmbiente()
		{
			ambienteGrid.Children.Clear();
			ambienteGrid.Columns = Ambiente.Colunas;
			ambienteGrid.Rows = Ambiente.Linhas;

			for (int y = 0; y < Ambiente.Linhas; y++)
			{
				for (int x = 0; x < Ambiente.Colunas; x++)
				{
					ambienteGrid.Children.Add(new EntidadeUC(new Coordenadas { X = x, Y = y }));
				}
			}
		}

		/// <summary>
		/// Seleciona os parâmetros do ambiente pela opção da combo box.
		/// </summary>
		/// <param name="sender">Quem disparou o método.</param>
		/// <param name="e">Argumentos de quem disparou.</param>
		private void AmbienteTamanho_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			ComboBoxItem itemSelecionado = ambienteTamanho.SelectedItem as ComboBoxItem;
			int tamanhoSelecionado;

			if (itemSelecionado != null && Int32.TryParse((string)itemSelecionado.Tag, out tamanhoSelecionado))
			{
				if (tamanhoSelecionado != -1)
				{
					try
					{
						_executor.Abort();
					}
					catch { }

					_executor = new Thread(ExecutorRun);

					LimpaLog();
					Ambiente.Criar(tamanhoSelecionado, tamanhoSelecionado);

					if (tamanhoSelecionado == 8)
					{
						if (!AlocaEntidadesAmbiente(2, 6, 2, 6, 2))
						{
							LogMessage("Não foi possível alocar as entidades pelos parâmetros informados.");
							return;
						}
					}
					else if (tamanhoSelecionado == 15)
					{
						if (!AlocaEntidadesAmbiente(3, 8, 4, 8, 4))
						{
							LogMessage("Não foi possível alocar as entidades pelos parâmetros informados.");
							return;
						}
					}
					else if (tamanhoSelecionado == 20)
					{
						if (!AlocaEntidadesAmbiente(20, 50, 20, 50, 20))
						{
							LogMessage("Não foi possível alocar as entidades pelos parâmetros informados.");
							return;
						}
					}

					DesenhaAmbiente();
					AtualizaEntidades();

					Ambiente.AmbienteChange += Ambiente_AmbienteChaged;

					_simula = true;
					_executor.Start();
				}
			}
		}

		/// <summary>
		/// Método executado quando há mudanças no ambiente.
		/// </summary>
		/// <param name="entidade">Entidade de mudou.</param>
		/// <param name="coordenadas">Coordenadas do que foi mudado.</param>
		private void Ambiente_AmbienteChaged(Entidade entidade, Coordenadas coordenadas)
		{
			Dispatcher.Invoke(() =>
			{
				AtualizaEntidade(entidade, coordenadas);
			});
		}

		/// <summary>
		/// Devolve uma entidade a partir de sua posição no ambiente.
		/// </summary>
		/// <param name="coordenadas">Posição do plano (entre colunas e linhas).</param>
		/// <returns>Entidade nessa posição.</returns>
		private EntidadeUC GetEntidade(Coordenadas coordenadas)
		{
			return ambienteGrid.Children.OfType<EntidadeUC>().ToList().Find(e => e.Coordenadas.X == coordenadas.X && e.Coordenadas.Y == coordenadas.Y);
		}

		/// <summary>
		/// Devolve todas as entidades que se encaixam nos parâmetros do predicado.
		/// </summary>
		/// <param name="predicado">Predicado para os parâmetros de pesquisa das entidades.</param>
		/// <returns>Entidades encontradas a partir do predicado.</returns>
		private List<EntidadeUC> GetEntidades(Predicate<EntidadeUC> predicado)
		{
			return ambienteGrid.Children.OfType<EntidadeUC>().ToList().FindAll(predicado);
		}

		/// <summary>
		/// Garante determinadas ações antes de fechar a janela.
		/// </summary>
		/// <param name="sender">Quem invocou o método.</param>
		/// <param name="e">Parâmetros de quem invocou.</param>
		private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			try
			{
				_executor.Abort();
			}
			catch { }
		}

		/// <summary>
		/// Controla a entrada de enter para executar um ciclo.
		/// </summary>
		/// <param name="sender">Quem invocou o método.</param>
		/// <param name="e">Parâmetros de quem invocou.</param>
		private void Window_KeyUp(object sender, System.Windows.Input.KeyEventArgs e)
		{
			if (e.Key == Key.Enter)
			{
				if (!_ciclosAutomaticos && _podeExecutar)
				{
					_podeExecutar = false;

					new Thread(() =>
					{
						RodaCiclo();
					}).Start();
				}
			}
		}

		/// <summary>
		/// Controla a mudança entre ciclos manuais para automáticos.
		/// </summary>
		/// <param name="sender">Quem invocou o método.</param>
		/// <param name="e">Parâmetros de quem invocou.</param>
		private void CiclosAutomaticos_Check_Change(object sender, RoutedEventArgs e)
		{
			_ciclosAutomaticos = (bool)ciclosAutomaticos.IsChecked;

			if (_ciclosAutomaticos)
			{
				try
				{
					_executor.Abort();
				}
				catch { }

				_executor = new Thread(ExecutorRun);
				_executor.Start();
			}
		}
		private void VelocidadeAgentes_Pasting(object sender, DataObjectPastingEventArgs e)
		{
			if (e.DataObject.GetDataPresent(typeof(String)))
			{
				String text = (String)e.DataObject.GetData(typeof(String));
				Regex regex = new Regex("[^0-9.-]+");
				if (regex.IsMatch(text))
				{
					e.CancelCommand();
				}
			}
			else
			{
				e.CancelCommand();
			}
		}
		private void VelocidadeAgentes_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			Regex regex = new Regex("[^0-9]+");
			e.Handled = regex.IsMatch(e.Text);
		}
		private void VelocidadeAgentes_TextChanged(object sender, TextChangedEventArgs e)
		{
			int val;
			Int32.TryParse(velocidadeAgentes.Text, out val);
			VelocidadeAgentes = val;
		}
		#endregion Métodos exclusivos para controle de interface.

	}
}
