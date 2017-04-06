using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int mapx = 10;
            int mapy = 10;
            char[] tomb1 = new char[mapx * mapy];
            for (int i = 0; i < mapx * mapy; i++)
            {
                tomb1[i] = ' ';
            }
            int x = mapx/2;
            int y = mapy/2;
            while (true)
            {
                tomb1[y * mapy + x] = '@';
                int counter = 0;
                Console.WriteLine();
                for (int i = 0; i < mapx + 2; i++)
                {
                    Console.Write('#');
                }
                Console.WriteLine();
                for (int i = 0; i < mapy; i++)
                {
                    Console.Write('#');
                    for (int c = 0; c < mapx; c++)
                    {
                        Console.Write(tomb1[counter]);
                        counter++;
                    }
                    Console.Write('#');
                    Console.WriteLine();
                }
                for (int i = 0; i < mapx + 2; i++)
                {
                    Console.Write('#');
                }
                var lol = Console.ReadKey();
                switch (lol.Key)
                {
                    case ConsoleKey.W: y = y - 1; break;
                    case ConsoleKey.A: x = x - 1; break;
                    case ConsoleKey.S: y = y + 1; break;
                    case ConsoleKey.D: x = x + 1; break;
                }
                Thread.Sleep(10);
            }
        }
    }
}
