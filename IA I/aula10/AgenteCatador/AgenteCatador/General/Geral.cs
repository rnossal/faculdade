using System;
using AgenteCatador.Model;
using System.Reflection;
using System.ComponentModel;
using System.Threading;

namespace AgenteCatador.General
{
	public class Geral
	{
		/// <summary>
		/// Variável random estática fora de thread para lidar com problemas de randomização baseada e ticks da thread camadora.
		/// </summary>
		[ThreadStatic] private static Random _localRandom;

		/// <summary>
		/// Verifica se a coordenada está livre tanto no lugar pesquisado.
		/// </summary>
		/// <param name="coordenadas">Posição do ambiente a ser consultada.</param>
		/// <returns>Se está ou não livre.</returns>
		public static bool EstaLivre(Coordenadas coordenadas)
		{
			if (!EstaLimite(coordenadas))
				return false;

			Entidade entidade = Ambiente.GetEntidade(coordenadas);

			if (!(entidade is Agente) && !(entidade is Lixo) && !(entidade is Lixeira))
				return true;

			return false;
		}

		/// <summary>
		/// Verifica se o lugar é possível de caminhar, mesmo que com lixo no chão.
		/// </summary>
		/// <param name="coordenadas">Posição do ambiente a ser consultada.</param>
		/// <returns>Se pode ou não caminhar por ali.</returns>
		public static bool PodeCaminhar(Coordenadas coordenadas)
		{
			if (!EstaLimite(coordenadas))
				return false;

			Entidade entidade = Ambiente.GetEntidade(coordenadas);

			if (!(entidade is Agente) && !(entidade is Lixeira) && !(entidade is Multiplo))
				return true;

			return false;
		}

		/// <summary>
		/// Verifica se a posição x e y informadas compreendem ao limite do ambiente.
		/// </summary>
		/// <param name="coordenadas">Posição do ambiente a ser consultada.</param>
		/// <returns>Se está ou não nos limites do ambiente.</returns>
		public static bool EstaLimite(Coordenadas coordenadas)
		{
			return coordenadas.X < Ambiente.Colunas && coordenadas.Y < Ambiente.Linhas && coordenadas.X >= 0 && coordenadas.Y >= 0;
		}


		public static bool EstaTrancado(Coordenadas coordenadas)
		{
			if (PodeCaminhar(GetCoordenadasPorDirecao(coordenadas, Direcoes.CIMA)) ||
				PodeCaminhar(GetCoordenadasPorDirecao(coordenadas, Direcoes.BAIXO)) ||
				PodeCaminhar(GetCoordenadasPorDirecao(coordenadas, Direcoes.ESQUERDA)) ||
				PodeCaminhar(GetCoordenadasPorDirecao(coordenadas, Direcoes.DIREITA)))
			{
				return false;
			}

			return true;
		}

		public static bool EstaLivreArredores(Coordenadas coordenadas)
		{
			if (EstaLivre(new Coordenadas { X = coordenadas.X + 1, Y = coordenadas.Y }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X - 1, Y = coordenadas.Y }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X, Y = coordenadas.Y + 1 }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X, Y = coordenadas.Y - 1 }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X + 1, Y = coordenadas.Y + 1 }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X + 1, Y = coordenadas.Y - 1 }) &&
				EstaLivre(new Coordenadas { X = coordenadas.X - 1, Y = coordenadas.Y + 1}) &&
				EstaLivre(new Coordenadas { X = coordenadas.X - 1, Y = coordenadas.Y - 1}))
			{
				return true;
			}

			return false;
		}

		/// <summary>
		/// Calcula a distância entre dos pontos usando teorema de pitágoras.
		/// </summary>
		/// <param name="ent1">Primeira entidade de comparação.</param>
		/// <param name="ent2">Segunda entidade de comparação.</param>
		/// <returns>Distância resultante entre os dois pontos.</returns>
		public static double DistanciaPontos(Entidade ent1, Entidade ent2)
		{
			return Math.Sqrt((Math.Pow((ent2.Coordenadas.X - ent1.Coordenadas.X), 2) + Math.Pow((ent2.Coordenadas.Y - ent1.Coordenadas.Y), 2)));
		}

		public static string GetDescricaoEnum(Enum valor)
		{
			FieldInfo fi = valor.GetType().GetField(valor.ToString());
			DescriptionAttribute[] attributes = (DescriptionAttribute[])fi.GetCustomAttributes(typeof(DescriptionAttribute), false);
			if (attributes.Length > 0)
			{
				return attributes[0].Description;
			}
			else
			{
				return valor.ToString();
			}
		}

		/// <summary>
		/// Retorna as coordenadas da direção que deve consultado a portir de um ponto de coordenada.
		/// </summary>
		/// <param name="coordenadas">Coordenadas a portir de onde deve olhar.</param>
		/// <param name="direcao">Direção para procurar as coordenadas.</param>
		/// <returns>Coordenada encontrada.</returns>
		public static Coordenadas GetCoordenadasPorDirecao(Coordenadas coordenadas, Direcoes direcao)
		{
			switch (direcao)
			{
				case Direcoes.NENHUMA:
					return new Coordenadas
					{
						X = coordenadas.X,
						Y = coordenadas.Y
					};
				case Direcoes.CIMA:
					return new Coordenadas
					{
						X = coordenadas.X,
						Y = coordenadas.Y - 1
					};
				case Direcoes.CIMAx2:
					return new Coordenadas
					{
						X = coordenadas.X,
						Y = coordenadas.Y - 2
					};
				case Direcoes.BAIXO:
					return new Coordenadas
					{
						X = coordenadas.X,
						Y = coordenadas.Y + 1
					};
				case Direcoes.BAIXOx2:
					return new Coordenadas
					{
						X = coordenadas.X,
						Y = coordenadas.Y + 2
					};
				case Direcoes.ESQUERDA:
					return new Coordenadas
					{
						X = coordenadas.X - 1,
						Y = coordenadas.Y
					};
				case Direcoes.ESQUERDAx2:
					return new Coordenadas
					{
						X = coordenadas.X - 2,
						Y = coordenadas.Y
					};
				case Direcoes.DIREITA:
					return new Coordenadas
					{
						X = coordenadas.X + 1,
						Y = coordenadas.Y
					};
				case Direcoes.DIREITAx2:
					return new Coordenadas
					{
						X = coordenadas.X + 2,
						Y = coordenadas.Y
					};
				default:
					return null;
			}
		}

		/// <summary>
		/// Gera um random thread safe.
		/// </summary>
		public static Random Random
		{
			get { return _localRandom ?? (_localRandom = new Random(unchecked(Environment.TickCount * 31 + Thread.CurrentThread.ManagedThreadId))); }
		}
	}
}
