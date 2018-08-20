using System;
using System.Collections.Generic;
using System.Security.Cryptography;

namespace AgenteCatador.General
{
	static class MyExtensions
	{
		/// <summary>
		/// Embaralha um tipo derivado da interface de lista.
		/// </summary>
		/// <typeparam name="T">Tipo</typeparam>
		/// <param name="list">Lista a ser embaralhada.</param>
		public static void Shuffle<T>(this IList<T> list)
		{
			int n = list.Count;
			while (n > 1)
			{
				n--;
				int k = Geral.Random.Next(n + 1);
				T value = list[k];
				list[k] = list[n];
				list[n] = value;
			}
		}
	}
}
