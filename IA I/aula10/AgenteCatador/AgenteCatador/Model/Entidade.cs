using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Definição de uma intidade genérica com as informações básicas comum a todos.
	/// </summary>
	public class Entidade
	{
		#region Atributos públicos.
		/// <summary>
		/// Posição no ambiente.
		/// </summary>
		public Coordenadas Coordenadas { get; set; }
		#endregion Atributos públicos.

		/// <summary>
		/// Entidade com posição pré definida de espaço.
		/// </summary>
		/// <param name="coordenadas">Posição y no ambiente.</param>
		public Entidade(Coordenadas coordenadas)
		{
			Coordenadas = coordenadas;
		}
	}
}
