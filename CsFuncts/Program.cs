using System;

namespace CsFuncts
{
  class Program
  {
    /* pass value by value */
    int pass_val_by_val(int i)
    {
      Console.Write("\n  Pass val by val");
      Console.Write("\n    input i = {0}", i);
      i += 2;
      Console.Write("\n    mutated value = {0}", i);
      return i;
    }
    /* pass value by reference */
    int pass_val_by_ref(ref int i)
    {
      Console.Write("\n  Pass val by ref");
      Console.Write("\n    input i = {0}", i);
      i += 2;
      Console.Write("\n    mutated value = {0}", i);
      return i;
    }
    /* pass reference by value */
    String pass_ref_by_val(String s)
    {
      Console.Write("\n  Pass ref by val");
      Console.Write("\n    input s = {0}", s);
      s += new String(" addendum");
      Console.Write("\n    mutated value = {0}", s);
      s = new string("another String");
      Console.Write("\n    new object = {0}", s);
      return s;
    }
    /* pass reference by reference */
    String pass_ref_by_ref(ref String s)
    {
      Console.Write("\n  Pass ref by ref");
      Console.Write("\n    input s = {0}", s);
      s += new String(" addendum");
      Console.Write("\n    mutated value = {0}", s);
      s = new string("another String");
      Console.Write("\n    new object = {0}", s);
      return s;
    }
    static void Main(string[] args)
    {
      Program demo = new Program();

      /* pass value by value */
      int i1 = 42;
      int r1 = demo.pass_val_by_val(i1);
      Console.Write("\n  return value = {0}", r1);
      Console.Write("\n  input i1 = {0}", i1);
      Console.WriteLine();

      /* pass value by reference */
      int i2 = -7;
      int r2 = demo.pass_val_by_ref(ref i2);
      Console.Write("\n  return value = {0}", r2);
      Console.Write("\n  input i2 = {0}", i2);
      Console.WriteLine();

      /* pass reference by value */
      String s3 = "a string";
      String r3 = demo.pass_ref_by_val(s3);
      Console.Write("\n  return value = {0}", r3);
      Console.Write("\n  input s3 = {0}", s3);
      Console.WriteLine();

      /* pass reference by reference */
      String s4 = "a string";
      String r4 = demo.pass_ref_by_ref(ref s4);
      Console.Write("\n  return value = {0}", r4);
      Console.Write("\n  input s4 = {0}", s4);
      Console.WriteLine();
    }
  }
}
