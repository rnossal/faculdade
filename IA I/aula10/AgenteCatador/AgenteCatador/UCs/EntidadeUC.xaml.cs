using AgenteCatador.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace AgenteCatador.UCs
{
	/// <summary>
	/// Interaction logic for EntidadeUC.xaml
	/// </summary>
	public partial class EntidadeUC : UserControl, INotifyPropertyChanged
	{
		#region Atributos privados.
		/// <summary>
		/// Tipo interno de entidade.
		/// </summary>
		private Entidades _tipo;
		/// <summary>
		/// Posição interna no ambiente.
		/// </summary>
		private Coordenadas _coordenadas;
		/// <summary>
		/// Quantidade interna de lixo orgânico que a entidade possui.
		/// </summary>
		private int _qtdLixoOrganico;
		/// <summary>
		/// Quantidade interna de lixo seco que a entidade possui.
		/// </summary>
		private int _qtdLixoSeco;
		/// <summary>
		/// capacidade máxima interna de lixo seco.
		/// </summary>
		private int _capacidadeMaximaLixoSeco;
		/// <summary>
		/// capacidade máxima interna de lixo orgânico.
		/// </summary>
		private int _capacidadeMaximaLixoOrganico;
		/// <summary>
		/// Numero interno do agente no ambiente.
		/// </summary>
		private int _numeroAgente;
		#endregion Atributos privados.

		#region Atributos públicos.
		/// <summary>
		/// Evento de propriedades modificadas.
		/// </summary>
		public event PropertyChangedEventHandler PropertyChanged;
		/// <summary>
		/// Posição no ambiente.
		/// </summary>
		public Coordenadas Coordenadas
		{
			get
			{
				return _coordenadas;
			}
		}
		/// <summary>
		/// Tipo da entidade.
		/// </summary>
		public Entidades Tipo
		{
			get
			{
				return _tipo;
			}
			set
			{
				_tipo = value;
				NotifyPropertyChanged("TipoEntidade");
			}
		}
		/// <summary>
		/// Exceção para caso seja entidade múltipla onde serão mais de uma entidade diferente.
		/// </summary>
		public List<Entidade> EntidadesMultiplo { get; set; }
		/// <summary>
		/// Quantidade de lixo orgânico que a entidade possui.
		/// </summary>
		public int QtdLixoOrganico
		{
			get
			{
				return _qtdLixoOrganico;
			}
			set
			{
				_qtdLixoOrganico = value;
				NotifyPropertyChanged("QtdLixoOrganico");
			}
		}
		/// <summary>
		/// Quantidade de lixo seco que a entidade possui.
		/// </summary>
		public int QtdLixoSeco
		{
			get
			{
				return _qtdLixoSeco;
			}
			set
			{
				_qtdLixoSeco = value;
				NotifyPropertyChanged("QtdLixoSeco");
			}
		}
		/// <summary>
		/// Capacidade máxima interna de lixo seco.
		/// </summary>
		public int CapacidadeMaximaLixoSeco
		{
			get
			{
				return _capacidadeMaximaLixoSeco;
			}
			set
			{
				_capacidadeMaximaLixoSeco = value;
				NotifyPropertyChanged("CapacidadeMaximaLixoSeco");
			}
		}
		/// <summary>
		/// Capacidade máxima interna de lixo orgânico.
		/// </summary>
		public int CapacidadeMaximaLixoOrganico
		{
			get
			{
				return _capacidadeMaximaLixoOrganico;
			}
			set
			{
				_capacidadeMaximaLixoOrganico = value;
				NotifyPropertyChanged("CapacidadeMaximaLixoOrganico");
			}
		}
		/// <summary>
		/// Numero do agente no ambiente.
		/// </summary>
		public int NumeroAgente
		{
			get
			{
				return _numeroAgente;
			}
			set
			{
				_numeroAgente = value;
				NotifyPropertyChanged("NumeroAgente");
			}
		}
		#endregion Atributos públicos.

		/// <summary>
		/// Cria uma UC com o tipo de entidade padrão (sem tipo de entidade).
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		public EntidadeUC(Coordenadas coordenadas)
		{
			InitializeComponent();
			SetInterface();

			PropertyChanged += EntidadeUC_PropertyChanged;

			_coordenadas = coordenadas;
		}

		/// <summary>
		/// Cria a UC com o tipo de entidade definido.
		/// </summary>
		/// <param name="tipo">Tipo de entidade que a UC irá assumir.</param>
		/// <param name="coordenadas">Posição no ambiente.</param>
		public EntidadeUC(Entidades tipo, Coordenadas coordenadas)
		{
			InitializeComponent();
			SetInterface();

			PropertyChanged += EntidadeUC_PropertyChanged;

			this.Tipo = tipo;
			_coordenadas = coordenadas;
		}

		/// <summary>
		/// Reseta todos os canvas e atributos que representam as entidades.
		/// </summary>
		private void ResetEntidades()
		{
			agenteView.Visibility = Visibility.Collapsed;
			lixeiraOrganicoView.Visibility = Visibility.Collapsed;
			lixeiraSecoView.Visibility = Visibility.Collapsed;
			lixoOrganicoView.Visibility = Visibility.Collapsed;
			lixoSecoView.Visibility = Visibility.Collapsed;

			_qtdLixoOrganico = _qtdLixoSeco = _capacidadeMaximaLixoSeco = _capacidadeMaximaLixoOrganico = _numeroAgente = 0;
		}

		/// <summary>
		/// Define estilos e outras informações de interface.
		/// </summary>
		private void SetInterface()
		{
			Brush bgColor = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#edeff0"));
			Brush borderColor = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#9f9f9f"));
			Brush agenteNumColor = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#D13334"));
			Brush agentePathColor = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#3180A4"));

			agenteNum.Foreground = agenteNumColor;
			agentePath.Fill = agentePathColor;
			entidadeGrid.Background = bgColor;
			//agenteCanvas.Background = bgColor;
			lixoOrganicoCanvas.Background = bgColor;
			lixeiraOrganicoCanvas.Background = bgColor;
			lixoSecoCanvas.Background = bgColor;
			lixeiraSecoCanvas.Background = bgColor;

			entidadeBorder.BorderBrush = borderColor;
		}

		/// <summary>
		/// Controlador de mudanças de atributos observáveis.
		/// </summary>
		/// <param name="sender">Quem disparou o método.</param>
		/// <param name="e">Argumentos de quem disparou.</param>
		private void EntidadeUC_PropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			switch (e.PropertyName)
			{
				case "TipoEntidade":
					ResetEntidades();

					switch (_tipo)
					{
						case Entidades.AGENTE:
							agenteView.Visibility = Visibility.Visible;
							break;
						case Entidades.LIXEIRA_ORGANICO:
							lixeiraOrganicoView.Visibility = Visibility.Visible;
							break;
						case Entidades.LIXEIRA_SECO:
							lixeiraSecoView.Visibility = Visibility.Visible;
							break;
						case Entidades.LIXO_ORGANICO:
							lixoOrganicoView.Visibility = Visibility.Visible;
							break;
						case Entidades.LIXO_SECO:
							lixoSecoView.Visibility = Visibility.Visible;
							break;
						case Entidades.MULTIPLO:
							if (!(EntidadesMultiplo is List<Entidade>))
								break;

							foreach(Entidade entidade in EntidadesMultiplo)
							{
								if (entidade is Lixo)
								{
									if ((entidade as Lixo).Tipo == TipoLixo.SECO)
									{
										lixoSecoView.Visibility = Visibility.Visible;
									}
									else
									{
										lixoOrganicoView.Visibility = Visibility.Visible;
									}
								}
								else if (entidade is Lixeira)
								{
									if ((entidade as Lixeira).Tipo == TipoLixo.SECO)
									{
										lixeiraSecoView.Visibility = Visibility.Visible;
										lixeiraSecoCount.Content = $"{(entidade as Lixeira).Lixos.Count.ToString()}/{(entidade as Lixeira).CapacidadeMaxima.ToString()}";
									}
									else
									{
										lixeiraOrganicoView.Visibility = Visibility.Visible;
										lixeiraOrganicoCount.Content = $"{(entidade as Lixeira).Lixos.Count.ToString()}/{(entidade as Lixeira).CapacidadeMaxima.ToString()}";
									}
								}
								else if (entidade is Agente)
								{
									agenteSecoCount.Content = $"{(entidade as Agente).SacoLixoSeco.Count.ToString()}/{(entidade as Agente).CapacidadeMaximaLixoSeco.ToString()}";
									agenteOrganicoCount.Content = $"{(entidade as Agente).SacoLixoOrganico.Count.ToString()}/{(entidade as Agente).CapacidadeMaximaLixoOrganico.ToString()}";
									agenteNum.Content = (entidade as Agente).Numero.ToString();

									agenteView.Visibility = Visibility.Visible;
								}
							}
							break;
					}
					break;
				case "QtdLixoOrganico":
					switch (_tipo)
					{
						case Entidades.AGENTE:
							agenteOrganicoCount.Content = $"{_qtdLixoOrganico.ToString()}/{_capacidadeMaximaLixoOrganico.ToString()}";
							break;
						case Entidades.LIXEIRA_ORGANICO:
							lixeiraOrganicoCount.Content = $"{_qtdLixoOrganico.ToString()}/{_capacidadeMaximaLixoOrganico.ToString()}";
							break;
					}
					break;
				case "QtdLixoSeco":
					switch (_tipo)
					{
						case Entidades.AGENTE:
							agenteSecoCount.Content = $"{_qtdLixoSeco.ToString()}/{_capacidadeMaximaLixoSeco.ToString()}";
							break;
						case Entidades.LIXEIRA_SECO:
							lixeiraSecoCount.Content = $"{_qtdLixoSeco.ToString()}/{_capacidadeMaximaLixoSeco.ToString()}";
							break;
					}
					break;
				case "CapacidadeMaximaLixoSeco":
					switch (_tipo)
					{
						case Entidades.AGENTE:
							agenteSecoCount.Content = $"{_qtdLixoSeco.ToString()}/{_capacidadeMaximaLixoSeco.ToString()}";
							break;
						case Entidades.LIXEIRA_SECO:
							lixeiraSecoCount.Content = $"{_qtdLixoSeco.ToString()}/{_capacidadeMaximaLixoSeco.ToString()}";
							break;
					}
					break;
				case "CapacidadeMaximaLixoOrganico":
					switch (_tipo)
					{
						case Entidades.AGENTE:
							agenteOrganicoCount.Content = $"{_qtdLixoOrganico.ToString()}/{_capacidadeMaximaLixoOrganico.ToString()}";
							break;
						case Entidades.LIXEIRA_ORGANICO:
							lixeiraOrganicoCount.Content = $"{_qtdLixoOrganico.ToString()}/{_capacidadeMaximaLixoOrganico.ToString()}";
							break;
					}
					break;
				case "NumeroAgente":
					agenteNum.Content = _numeroAgente.ToString();
					break;
			}
		}

		/// <summary>
		/// Interno responsável por disparar o evento.
		/// </summary>
		/// <param name="nome">Nome do evento disparado.</param>
		internal void NotifyPropertyChanged(String nome)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nome));
		}
	}
}
