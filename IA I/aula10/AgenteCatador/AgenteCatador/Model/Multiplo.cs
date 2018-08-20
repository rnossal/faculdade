using System.Collections.Generic;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Definição de uma entidade que é na verdade uma lista de outras entidades "reais" (usado para armazerar mais de uma entidade da matriz).
	/// </summary>
	public class Multiplo : Entidade
	{
		/// <summary>
		/// Lista com as entidades que ocupam o mesmo espaço.
		/// </summary>
		public List<Entidade> Entidades { get; set; }

		public Multiplo(Coordenadas coordenadas) : base(coordenadas)
		{
			Entidades = new List<Entidade>();
		}
	}
}
