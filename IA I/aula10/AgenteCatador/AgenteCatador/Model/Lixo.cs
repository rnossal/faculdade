using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Definição de uma entidade de lixo.
	/// </summary>
	public class Lixo : Entidade
	{
		#region Atributos públicos.
		/// <summary>
		/// Tipo de lixo que o lixo suporta.
		/// </summary>
		public TipoLixo Tipo { get; set; }
		#endregion Atributos públicos.

		/// <summary>
		/// Lixo com informações básicas do ambiente e tipo.
		/// </summary>
		/// <param name="coordenadas">Posição no ambiente.</param>
		/// <param name="tipo">Tipo de lixo que ele é.</param>
		public Lixo(Coordenadas coordenadas, TipoLixo tipo) : base(coordenadas)
		{
			Tipo = tipo;
		}
	}
}
