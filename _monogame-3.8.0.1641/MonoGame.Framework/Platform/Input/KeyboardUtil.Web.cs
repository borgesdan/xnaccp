using System;

namespace Microsoft.Xna.Framework.Input
{
    public static class KeyboardUtil
    {
        public static Keys ToXna (int key, int location)
        {
            switch (key)
            {
                case 8:
                    return Keys.Back;
                case 9:
                    return Keys.Tab;
                case 13:
                    return Keys.Enter;
                case 16:
                    return location == 1 ? Keys.LeftShift : Keys.RightShift;
                case 17:
                    return location == 1 ? Keys.LeftControl : Keys.RightControl;
                case 18:
                    return location == 1 ? Keys.LeftAlt : Keys.RightAlt;
                case 19:
                    return Keys.Pause;
                case 20:
                    return Keys.CapsLock;
                case 27:
                    return Keys.Escape;
                case 32:
                    return Keys.Space;
                case 33:
                    return Keys.PageUp;
                case 34:
                    return Keys.PageDown;
                case 35:
                    return Keys.End;
                case 36:
                    return Keys.Home;
                case 37:
                    return Keys.Left;
                case 38:
                    return Keys.Up;
                case 39:
                    return Keys.Right;
                case 40:
                    return Keys.Down;
                case 45:
                    return Keys.Insert;
                case 46:
                    return Keys.Delete;
                case 48:
                    return Keys.D0;
                case 49:
                    return Keys.D1;
                case 50:
                    return Keys.D2;
                case 51:
                    return Keys.D3;
                case 52:
                    return Keys.D4;
                case 53:
                    return Keys.D5;
                case 54:
                    return Keys.D6;
                case 55:
                    return Keys.D7;
                case 56:
                    return Keys.D8;
                case 57:
                    return Keys.D9;
                case 65:
                    return Keys.A;
                case 66:
                    return Keys.B;
                case 67:
                    return Keys.C;
                case 68:
                    return Keys.D;
                case 69:
                    return Keys.E;
                case 70:
                    return Keys.F;
                case 71:
                    return Keys.G;
                case 72:
                    return Keys.H;
                case 73:
                    return Keys.I;
                case 74:
                    return Keys.J;
                case 75:
                    return Keys.K;
                case 76:
                    return Keys.L;
                case 77:
                    return Keys.M;
                case 78:
                    return Keys.N;
                case 79:
                    return Keys.O;
                case 80:
                    return Keys.P;
                case 81:
                    return Keys.Q;
                case 82:
                    return Keys.R;
                case 83:
                    return Keys.S;
                case 84:
                    return Keys.T;
                case 85:
                    return Keys.U;
                case 86:
                    return Keys.V;
                case 87:
                    return Keys.W;
                case 88:
                    return Keys.X;
                case 89:
                    return Keys.Y;
                case 90:
                    return Keys.Z;
                case 96:
                    return Keys.NumPad0;
                case 97:
                    return Keys.NumPad1;
                case 98:
                    return Keys.NumPad2;
                case 99:
                    return Keys.NumPad3;
                case 100:
                    return Keys.NumPad4;
                case 101:
                    return Keys.NumPad5;
                case 102:
                    return Keys.NumPad6;
                case 103:
                    return Keys.NumPad7;
                case 104:
                    return Keys.NumPad8;
                case 105:
                    return Keys.NumPad9;
                case 106:
                    return Keys.Multiply;
                case 107:
                    return Keys.Add;
                case 109:
                    return Keys.Subtract;
                case 110:
                    return Keys.Decimal;
                case 111:
                    return Keys.Divide;
                case 112:
                    return Keys.F1;
                case 113:
                    return Keys.F2;
                case 114:
                    return Keys.F3;
                case 115:
                    return Keys.F4;
                case 116:
                    return Keys.F5;
                case 117:
                    return Keys.F6;
                case 118:
                    return Keys.F7;
                case 119:
                    return Keys.F8;
                case 120:
                    return Keys.F9;
                case 121:
                    return Keys.F10;
                case 122:
                    return Keys.F11;
                case 123:
                    return Keys.F12;
                case 14:
                    return Keys.NumLock;
                case 145:
                    return Keys.Scroll;
                case 186:
                    return Keys.OemSemicolon;
                case 187:
                    return Keys.OemPlus;
                case 188:
                    return Keys.OemComma;
                case 189:
                    return Keys.OemMinus;
                case 190:
                    return Keys.OemPeriod;
                case 191:
                    return Keys.OemQuestion;
                case 192:
                    return Keys.OemTilde;
                case 219:
                    return Keys.OemOpenBrackets;
                case 220:
                    return Keys.OemPipe;
                case 221:
                    return Keys.OemCloseBrackets;
                case 222:
                    return Keys.OemQuotes;
            }

            return Keys.None;
        }
    }
}

