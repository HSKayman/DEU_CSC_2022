using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Schema;

namespace _2017280030_OOP_HomeWorkIII
{
    internal class TextAnalsysy
    {
        private readonly MySpecialList<string> wordList;
        private readonly MySpecialDirectory<string, int> wordFrequence;
        public TextAnalsysy()
        {
           wordList=new MySpecialList<string>();
           wordFrequence=new MySpecialDirectory<string, int>();
        }
        internal void TextToWords(string text)
        {
            try
            {
                if (text.Equals(String.Empty) || String.Compare(text, " ") == 0)
                {
                    throw new Error("Wrong Input");
                }
                string words = text.Replace(",", "").Replace(".", "").Replace("?", "").Replace("!", "").Replace("\"", "").Replace(";", "")
                    .Replace(":", "").Replace("(", "").Replace(")", "").Replace("\"", "").Replace("\'", "").Trim();
                foreach (string word in words.Split(' '))
                    wordList.Add(word.ToLower());
            }catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        }
        static protected TextAnalsysy Input()
        {
            TextAnalsysy text = new TextAnalsysy();
            try
            {
                Console.WriteLine("> Please Enter 1. Text :");
                text.TextToWords(Console.ReadLine());
                Console.WriteLine("> Please Enter 2. Text :");
                text.TextToWords(Console.ReadLine());
                Console.WriteLine("> Please Enter 3. Text :");
                text.TextToWords(Console.ReadLine());
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
                return null;
            }
            return text;
        }
        internal void Write(bool i)
        {
            Error.ErrorAll(() => {
                if (i)
                {
                    if (this.wordList.Count == 0 || this.wordList.uniqueValueList.Count == 0)
                    {
                        throw new Error("Try Again Please!");
                    }
                    Console.WriteLine("------------------------");
                    Console.WriteLine("Number of all Word :     {0}", this.wordList.Count);
                    Console.WriteLine();
                    Console.WriteLine("Number of unique Word :  {0}", this.wordList.uniqueValueList.Count);
                    Console.WriteLine();
                    Console.WriteLine("------------------------");
                }
                else
                {
                    int num; List<string> words;
                    Console.WriteLine("Word & Frequency");
                    this.wordFrequence.PrintValue();
                    (num, words) = this.FindFrequence();
                    Console.WriteLine();
                    if (num == 0 || words is null)
                        return;
                    Console.Write("The most commonly used words or word:           ");
                    foreach (string word in words)
                        Console.Write("{0}, ", word);
                    Console.WriteLine();
                    Console.WriteLine("The most commonly used word's Frequency: {0}", num);
                    Console.WriteLine("-------------------------------------");
                } });
           
          
        }
        internal static void General()
        {
            Error.ErrorAll(() =>
            {
                TextAnalsysy analsysy = Input();
                analsysy.wordList.PrepareToHashSet();
                analsysy.wordList.ComputeToUniqieValueList();
                analsysy.Write(true);
                Console.WriteLine();
                analsysy.ConvertToDirectory();
                analsysy.Write(false);
            });
            
        }
        internal void ConvertToDirectory()
        {
            foreach (string word in this.wordList.uniqueValueList)
            {
                int i = 0;
                foreach (string secondword in this.wordList)
                    if (String.Compare(word, secondword) == 0)
                        i += 1;
                this.wordFrequence.Add(word, i);
            }
        }
        internal (int,List<string>) FindFrequence()
        {
            int maxi = 0;
            string word = String.Empty;
            List<string> words = new List<string>();
            Error.ErrorAll(() =>
            {
                for (int i = 0; i < this.wordFrequence.count; ++i)
                {
                    string iword = null;
                    int imaxi = 0;
                    (iword, imaxi) = this.wordFrequence.GetValue(i);
                    if (maxi < imaxi)
                    {
                        maxi = imaxi;
                        word = iword;
                    }
                }
                if (maxi == 0 || String.Compare(word, String.Empty) == 0)
                {
                    throw new Error("Words aree Empty!");
                }
                else
                {
                    for (int i = 0; i < this.wordFrequence.count; ++i)
                    {
                        string iword = null;
                        int imaxi = 0;
                        (iword, imaxi) = this.wordFrequence.GetValue(i);
                        if (maxi == imaxi)
                        {
                            words.Add(iword);
                        }
                    }
                }
            });
            
            return (maxi, words);
        }
    }
}
