using System.ComponentModel;

namespace AgenteCatador.Model
{
	/// <summary>
	/// Informações de tipos de entidades suportados.
	/// </summary>
	public enum Entidades
	{
		[Description("Nenhum")]
		NENHUM = 0,
		[Description("Agente Catador de Lixo")]
		AGENTE = 1,
		[Description("Lixo Orgânico")]
		LIXO_ORGANICO = 2,
		[Description("Lixo SECO")]
		LIXO_SECO = 3,
		[Description("Lixeira Orgânico")]
		LIXEIRA_ORGANICO = 4,
		[Description("Lixeira Seco")]
		LIXEIRA_SECO = 5,
		[Description("Múltiplo")]
		MULTIPLO = 6
	}

	/// <summary>
	/// Informações de tipos de lixo que uma lixeira ou lixo deverá possuir.
	/// </summary>
	public enum TipoLixo
	{
		[Description("Nenhum")]
		NENHUM = 0,
		[Description("Lixo Seco")]
		SECO = 1,
		[Description("Lixo Orgânico")]
		ORGANICO = 2
	}

	/// <summary>
	/// Direções básicas que um agente pode trabalhar.
	/// </summary>
	public enum Direcoes
	{
		[Description("Nenhuma")]
		NENHUMA = 0,
		[Description("Cima")]
		CIMA = 1,
		[Description("Cima da casa em cima")]
		CIMAx2 = 2,
		[Description("Embaixo")]
		BAIXO = 3,
		[Description("Embaixo da casa embaixo")]
		BAIXOx2 = 4,
		[Description("Esquerda")]
		ESQUERDA = 5,
		[Description("Esquerda da casa da esquerda")]
		ESQUERDAx2 = 6,
		[Description("Direita")]
		DIREITA = 7,
		[Description("Direita da casa da direita")]
		DIREITAx2 = 8
	}
}
