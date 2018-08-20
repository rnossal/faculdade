using System.Collections.ObjectModel;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Definição de uma entidade de lixeira.
	/// </summary>
	public class Lixeira : Entidade
	{
		#region Atributos públicos.
		/// <summary>
		/// Tipo de lixo que a lixeira suporta.
		/// </summary>
		public TipoLixo Tipo { get; set; }
		/// <summary>
		/// Capacidade máxima da lixeira
		/// </summary>
		public int CapacidadeMaxima { get; set; }
		/// <summary>
		/// Lixos que estão dentro da lixeira.
		/// </summary>
		public ObservableCollection<Lixo> Lixos { get; set; }
		#endregion Atributos públicos.

		/// <summary>
		/// Lixeira com informações básicas do ambiente.
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		/// <param name="tipo">Tipo de lixo que ela suporta.</param>
		public Lixeira(Coordenadas coordenadas, TipoLixo tipo) : base(coordenadas)
		{
			Lixos = new ObservableCollection<Lixo>();
			Tipo = tipo;
		}

		/// <summary>
		/// Verifica se a lixeira está cheia.
		/// </summary>
		/// <returns>Status de resposta.</returns>
		public bool EstaCheia()
		{
			return Lixos.Count >= CapacidadeMaxima;
		}
	}
}
