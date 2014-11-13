using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CTPCommon
{

    public abstract class ByteSwap<TT>
    {


        protected  Byte[] StructToBytes<T>(T obj) where T : struct,IByteSwap
        {
            T structure = (T)obj;
            structure.Swap();
            Int32 size = Marshal.SizeOf(structure);
            IntPtr buffer = Marshal.AllocHGlobal(size);
            try
            {
                Marshal.StructureToPtr(structure, buffer, false);
                Byte[] bytes = new Byte[size];
                Marshal.Copy(buffer, bytes, 0, size);
                return bytes;
            }
            finally
            {
                Marshal.FreeHGlobal(buffer);
            }
        }
        protected  T BytesToStruct<T>(Byte[] bytes) where T : struct,IByteSwap
        {
            Int32 size = Marshal.SizeOf(typeof(T));
            IntPtr buffer = Marshal.AllocHGlobal(size);
            try
            {
                Marshal.Copy(bytes, 0, buffer, size);
                T obj = (T)Marshal.PtrToStructure(buffer, typeof(T));
                obj.Swap();
                return obj;
            }
            finally
            {
                Marshal.FreeHGlobal(buffer);
            }
        }





        public abstract Byte[] ToBytes();

        public abstract int Lenght { get; }
    }



    public static class ByteSwapHelp
    {

        public static Byte[] StructToBytes<T>(T obj) where T : IByteSwap
        {
            T structure = (T)obj;
            structure.Swap();
            Int32 size = Marshal.SizeOf(structure);
            IntPtr buffer = Marshal.AllocHGlobal(size);
            try
            {
                Marshal.StructureToPtr(structure, buffer, false);
                Byte[] bytes = new Byte[size];
                Marshal.Copy(buffer, bytes, 0, size);
                return bytes;
            }
            finally
            {
                Marshal.FreeHGlobal(buffer);
            }
        }
        public static T BytesToStruct<T>(Byte[] bytes) where T : struct,IByteSwap
        {
            Int32 size = Marshal.SizeOf(typeof(T));
            IntPtr buffer = Marshal.AllocHGlobal(size);
            try
            {
                Marshal.Copy(bytes, 0, buffer, size);
                T obj = (T)Marshal.PtrToStructure(buffer, typeof(T));
                obj.Swap();
                return obj;
            }
            finally
            {
                Marshal.FreeHGlobal(buffer);
            }
        }



        public static UInt16 ReverseBytes(UInt16 value)
        {
            return (UInt16)((value & 0xFFU) << 8 | (value & 0xFF00U) >> 8);
        }
        public static Int16 ReverseBytes(Int16 value)
        {
            return (Int16)ReverseBytes((UInt16)value);
        }
        // 翻转字节顺序 (32-bit)
        public static UInt32 ReverseBytes(UInt32 value)
        {
            return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
                   (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
        }
        public static Int32 ReverseBytes(Int32 value)
        {
            return (Int32)ReverseBytes((UInt32)value);
        }
        // 翻转字节顺序 (64-bit)
        public static UInt64 ReverseBytes(UInt64 value)
        {
            return (value & 0x00000000000000FFUL) << 56 | (value & 0x000000000000FF00UL) << 40 |
                   (value & 0x0000000000FF0000UL) << 24 | (value & 0x00000000FF000000UL) << 8 |
                   (value & 0x000000FF00000000UL) >> 8 | (value & 0x0000FF0000000000UL) >> 24 |
                   (value & 0x00FF000000000000UL) >> 40 | (value & 0xFF00000000000000UL) >> 56;
        }



        public static double ReverseBytes(double value)
        {
            long bit = BitConverter.DoubleToInt64Bits(value);
            long rbit = (long)ReverseBytes((ulong)bit);
            double rdouble = BitConverter.Int64BitsToDouble(rbit);
            return rdouble;
        }
    }
}
