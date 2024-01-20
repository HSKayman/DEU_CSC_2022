using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Linq.Expressions;
using System.Threading;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;

namespace _2017280030_OOP_HomeworkII
{
    [Serializable]
     internal class TextInfo
    {
        private int numberOfWord;
        private int numberOfSentence;
        private string mostRepeatedWord;
        private int numberOfMostRepeatedWord;
        public TextInfo(StringBuilder text)
        {
            if (text == null)
                throw new Error("Transactions Failed!");
            else
            { 
                (numberOfSentence,numberOfWord, mostRepeatedWord, numberOfMostRepeatedWord) = Calculate(text);
                if (mostRepeatedWord == null)
                {
                    throw new Error("Transactions Failed!");
                }
            }
        }
        public TextInfo()
        {
            Deserialing();
        }
        private void Deserialing()
        {
            
            try
            {
                FileStream fileStream;
                if (File.Exists(@"data"))
                {
                    fileStream = new FileStream(@"data", FileMode.Open, FileAccess.Read,FileShare.None);
                }
                else
                {
                    throw new Error("File not Found ");
                }
                BinaryFormatter binary = new BinaryFormatter();
                TextInfo a=(TextInfo)binary.Deserialize(fileStream);
                numberOfWord=a.numberOfWord;
                numberOfSentence = a.numberOfSentence;
                mostRepeatedWord = a.mostRepeatedWord;
                numberOfMostRepeatedWord = a.numberOfMostRepeatedWord;
                fileStream.Close();
            }
            catch (Exception exception)
            {
                string message = "There was a problem while deserializing " + exception.Message;

                throw new Error(message);
            }
        }
        static internal void Serialing(TextInfo textInfo)
        {
            FileStream fileStream = null;
            try
            {
                fileStream = new FileStream(@"data", FileMode.OpenOrCreate, FileAccess.Write);
                BinaryFormatter writer = new BinaryFormatter();
                writer.Serialize(fileStream, textInfo);


            }
            catch (Exception exception)
            {
                string message = "There was a problem while serializing " + exception.Message;

                throw new Error(message);
            }
            finally
            {
                fileStream.Close();
            }
        }

        static public TextInfo Reader()
        {
            FileStream fileStream=null;
            TextInfo textInfo=null;
            try
            {
                if (File.Exists(@"odev2-oku.txt"))
                {
                    fileStream = new FileStream(@"odev2-oku.txt", FileMode.Open, FileAccess.ReadWrite);
                }
                else
                {
                    throw new Error("File not Found");
                }
                StreamReader streams = new StreamReader(fileStream);
                
                StringBuilder stringBuilder = new StringBuilder(streams.ReadToEnd().ToString());
                
                textInfo = new TextInfo(stringBuilder);
                streams.Close();

            }
            catch (ArgumentException exception)
            {
                string message = "There is a Problem inside File!" + exception.Message;
                Error.ErrorAll(() =>
                {
                    throw new Error(message);
                });
            }
            catch (Exception exception)
            {
                string message = "There is a Problem About File!" + exception.Message;

                Error.ErrorAll(() =>
                {
                    throw new Error(message);
                });
            }
            finally
            {
                fileStream.Close();
            }
            return textInfo;
        }
        internal void Print()
        {
            Console.WriteLine("Total number of words in the text: "+this.numberOfWord.ToString());
            Console.WriteLine("Total number of sentencees in the text: "+this.numberOfSentence.ToString());
            Console.WriteLine("Most repeated word and number of the word: {0},  {1} ",this.mostRepeatedWord, this.numberOfMostRepeatedWord.ToString());
            Console.WriteLine("Press Any Key...");
            Console.ReadKey();
        }

        private (int, int, string, int) Calculate(StringBuilder stringBuilder)
        {
            string strings = stringBuilder.ToString();
            int countSentence = 0;
            for (int i = 1; i < strings.Length; ++i)
            {
                if (strings[i] == '!' || strings[i] == '?')
                    ++countSentence;
                 else if (strings[i] == '.' && !Char.IsUpper(strings[i - 1]))//Kisaltmalari cumle saymamasi icin
                    ++countSentence;
            }
            Dictionary<string, int> dictionary = new Dictionary<string, int>();
            string[] texts=strings.Trim().Replace(",", "").Replace(".","").Replace("?","").Replace("!","").Replace("\"","").Replace(";", "").Split(' ');

            foreach (string text in texts)
                if (dictionary.ContainsKey(text.ToLower()))
                    dictionary[text.ToLower()]++;
                else
                    dictionary.Add(text.ToLower(), 1);
            
            string repeatedWordC=null;
            int repeatedWord=-1;
            int Count = 0;
            foreach (KeyValuePair<string, int> word in dictionary)
            {
                Count += word.Value;
                if (repeatedWord < word.Value) 
                {
                    repeatedWord = word.Value;
                    repeatedWordC = word.Key;
                }
            }
            return (countSentence,Count, repeatedWordC,repeatedWord);
        }
    }
}
