#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string input_line;
    string filename("INPUTtest.txt");
    ifstream input_file(filename);
    int ACTTable[86][22] = { 0, };
    ACTTable[0][0] = 5; ACTTable[0][20] = 6; ACTTable[0][21] = -4; ACTTable[1][21] = 999; ACTTable[2][0] = 5;
    ACTTable[2][20] = 6; ACTTable[2][21] = -4; ACTTable[3][0] = 5; ACTTable[3][20] = 6; ACTTable[3][21] = -4;
    ACTTable[4][0] = 5; ACTTable[4][20] = 6; ACTTable[4][21] = -4; ACTTable[5][1] = 10; ACTTable[6][1] = 12;
    ACTTable[7][21] = -1; ACTTable[8][21] = -2; ACTTable[9][21] = -3; ACTTable[10][2] = 13; ACTTable[10][3] = 15;
    ACTTable[10][8] = 14; ACTTable[11][2] = 16; ACTTable[12][12] = 17; ACTTable[13][0] = -5; ACTTable[13][1] = -5;
    ACTTable[13][13] = -5; ACTTable[13][15] = -5; ACTTable[13][16] = -5; ACTTable[13][19] = -5; ACTTable[13][20] = -5;
    ACTTable[13][21] = -5; ACTTable[14][0] = 19; ACTTable[14][9] = -22; ACTTable[15][1] = 28; ACTTable[15][4] = 22;
    ACTTable[15][5] = 23; ACTTable[15][6] = 24; ACTTable[15][8] = 26; ACTTable[15][11] = 29; ACTTable[16][0] = -6;
    ACTTable[16][1] = -6; ACTTable[16][13] = -6; ACTTable[16][15] = -6; ACTTable[16][16] = -6; ACTTable[16][19] = -6;
    ACTTable[16][20] = -6; ACTTable[16][21] = -6; ACTTable[17][0] = 5; ACTTable[17][13] = -39; ACTTable[18][9] = 33;
    ACTTable[19][1] = 34; ACTTable[20][2] = -7; ACTTable[21][2] = -8; ACTTable[22][2] = -9; ACTTable[23][2] = -10;
    ACTTable[24][2] = -11; ACTTable[25][2] = -13; ACTTable[25][7] = 35; ACTTable[25][9] = -13; ACTTable[26][1] = 28;
    ACTTable[26][8] = 26; ACTTable[26][11] = 29; ACTTable[27][2] = -15; ACTTable[27][7] = -15; ACTTable[27][9] = -15;
    ACTTable[28][10] = 37; ACTTable[28][2] = -18; ACTTable[28][7] = -18; ACTTable[28][9] = -18; ACTTable[28][10] = -18;
    ACTTable[29][2] = -19; ACTTable[29][7] = -19; ACTTable[29][9] = -19; ACTTable[29][10] = -19; ACTTable[30][13] = 38;
    ACTTable[31][0] = 5; ACTTable[31][13] = -39; ACTTable[32][0] = 5; ACTTable[32][13] = -39; ACTTable[33][12] = 41;
    ACTTable[34][9] = -24; ACTTable[34][14] = 43; ACTTable[35][1] = 28; ACTTable[35][8] = 26; ACTTable[35][11] = 29;
    ACTTable[36][9] = 45; ACTTable[37][1] = 28; ACTTable[37][11] = 29; ACTTable[38][0] = -36; ACTTable[38][20] = -36;
    ACTTable[38][21] = -36; ACTTable[39][13] = -37; ACTTable[40][13] = -38; ACTTable[41][0] = 53; ACTTable[41][1] = 54;
    ACTTable[41][13] = -26; ACTTable[41][15] = 51; ACTTable[41][16] = 52; ACTTable[41][19] = -26; ACTTable[42][9] = -21;
    ACTTable[43][0] = 55; ACTTable[44][2] = -12; ACTTable[44][9] = -12; ACTTable[45][2] = -14; ACTTable[45][9] = -14;
    ACTTable[46][2] = -16; ACTTable[46][7] = -16; ACTTable[46][9] = -16; ACTTable[47][19] = 57; ACTTable[48][0] = 53;
    ACTTable[48][1] = 54; ACTTable[48][13] = -26; ACTTable[48][15] = 51; ACTTable[48][16] = 52; ACTTable[48][19] = -26;
    ACTTable[49][0] = -27; ACTTable[49][1] = -27; ACTTable[49][13] = -27; ACTTable[49][15] = -27; ACTTable[49][16] = -27; ACTTable[49][19] = -27;
    ACTTable[50][2] = 59; ACTTable[51][8] = 60; ACTTable[52][8] = 61; ACTTable[53][1] = 62;
    ACTTable[54][3] = 15; ACTTable[55][1] = 63; ACTTable[56][13] = 64; ACTTable[57][1] = 28; ACTTable[57][4] = 22;
    ACTTable[57][5] = 23; ACTTable[57][6] = 24; ACTTable[57][8] = 26; ACTTable[57][11] = 29; ACTTable[58][13] = -25;
    ACTTable[58][19] = -25; ACTTable[59][0] = -28; ACTTable[59][1] = -28; ACTTable[59][13] = -28; ACTTable[59][15] = -28; ACTTable[59][16] = -28; ACTTable[59][19] = -28;
    ACTTable[60][6] = 67; ACTTable[61][6] = 67; ACTTable[62][2] = 13; ACTTable[62][3] = 15;
    ACTTable[63][9] = -24; ACTTable[63][14] = 43; ACTTable[64][0] = -20; ACTTable[64][13] = -20;
    ACTTable[64][20] = -20; ACTTable[64][21] = -20; ACTTable[65][2] = 70; ACTTable[66][9] = 71; ACTTable[67][9] = -32;
    ACTTable[67][17] = 72; ACTTable[68][9] = 73; ACTTable[69][9] = -23; ACTTable[70][13] = -35; ACTTable[71][12] = 74;
    ACTTable[72][6] = 67; ACTTable[73][12] = 76; ACTTable[74][0] = 53; ACTTable[74][1] = 54; ACTTable[74][13] = -26;
    ACTTable[74][15] = 51; ACTTable[74][16] = 52; ACTTable[74][19] = -26; ACTTable[75][9] = -31; ACTTable[76][0] = 53;
    ACTTable[76][1] = 54; ACTTable[76][13] = -26; ACTTable[76][15] = 51; ACTTable[76][16] = 52; ACTTable[76][19] = -26;
    ACTTable[77][13] = 79; ACTTable[78][13] = 80; ACTTable[79][0] = -34; ACTTable[79][1] = -34; ACTTable[79][13] = -34;
    ACTTable[79][15] = -34; ACTTable[79][16] = -34; ACTTable[79][18] = 82; ACTTable[79][19] = -34; ACTTable[80][0] = -30;
    ACTTable[80][1] = -30; ACTTable[80][13] = -30; ACTTable[80][15] = -30; ACTTable[80][16] = -30; ACTTable[80][19] = -30;
    ACTTable[81][0] = -29; ACTTable[81][1] = -29; ACTTable[81][13] = -29; ACTTable[81][15] = -29; ACTTable[81][16] = -29;
    ACTTable[81][19] = -29; ACTTable[82][12] = 83; ACTTable[83][0] = 53; ACTTable[83][1] = 54; ACTTable[83][13] = -26;
    ACTTable[83][15] = 51; ACTTable[83][16] = 52; ACTTable[83][19] = -26; ACTTable[84][13] = 85; ACTTable[85][0] = -33;
    ACTTable[85][1] = -33; ACTTable[85][13] = -33; ACTTable[85][15] = -33; ACTTable[85][16] = -33; ACTTable[85][19] = -33;

    int GOTOTable[86][19] = { 0, };
    GOTOTable[0][1] = 1; GOTOTable[0][2] = 2; GOTOTable[0][9] = 3; GOTOTable[0][17] = 4; GOTOTable[2][1] = 7;
    GOTOTable[2][2] = 2; GOTOTable[2][9] = 3; GOTOTable[2][17] = 4; GOTOTable[3][1] = 8; GOTOTable[3][2] = 2;
    GOTOTable[3][9] = 3; GOTOTable[3][17] = 4; GOTOTable[4][1] = 9; GOTOTable[4][2] = 2; GOTOTable[4][9] = 3;
    GOTOTable[4][17] = 4; GOTOTable[5][3] = 11; GOTOTable[14][10] = 18; GOTOTable[15][4] = 20; GOTOTable[15][5] = 21;
    GOTOTable[15][6] = 25; GOTOTable[15][8] = 27; GOTOTable[17][2] = 31; GOTOTable[17][9] = 32; GOTOTable[17][18] = 30;
    GOTOTable[26][5] = 36; GOTOTable[26][6] = 25; GOTOTable[26][8] = 27; GOTOTable[31][2] = 31; GOTOTable[31][9] = 32;
    GOTOTable[31][18] = 39; GOTOTable[32][2] = 31; GOTOTable[32][9] = 32; GOTOTable[32][18] = 40; GOTOTable[34][11] = 42;
    GOTOTable[35][5] = 44; GOTOTable[35][6] = 25; GOTOTable[35][8] = 27; GOTOTable[37][6] = 46; GOTOTable[37][8] = 27;
    GOTOTable[41][2] = 49; GOTOTable[41][3] = 50; GOTOTable[41][12] = 47; GOTOTable[41][13] = 48; GOTOTable[47][16] = 56;
    GOTOTable[48][2] = 49; GOTOTable[48][3] = 50; GOTOTable[48][12] = 58; GOTOTable[48][13] = 48; GOTOTable[53][3] = 11;
    GOTOTable[57][4] = 65; GOTOTable[57][5] = 21; GOTOTable[57][6] = 25; GOTOTable[57][8] = 27; GOTOTable[60][14] = 66;
    GOTOTable[61][14] = 68; GOTOTable[63][11] = 69; GOTOTable[72][14] = 75; GOTOTable[74][2] = 49; GOTOTable[74][3] = 50;
    GOTOTable[74][12] = 77; GOTOTable[74][13] = 48; GOTOTable[76][2] = 49; GOTOTable[76][3] = 50; GOTOTable[76][12] = 78;
    GOTOTable[76][13] = 48; GOTOTable[79][15] = 81; GOTOTable[83][2] = 49; GOTOTable[83][3] = 50; GOTOTable[83][12] = 84;
    GOTOTable[83][13] = 48;

    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    stack<int> stack;
    string word;
    vector<string> words;
    while (input_file >> word)
        words.push_back(word);
    input_file.close();
    string rules[42] = {
        // Non-Terminal
        /*0*/ "SCODE", /*1*/"CODE",/*2*/ "VDECL",/*3*/ "ASSIGN",/*4*/ "RHS",/*5*/ "EXPR",
        /*6*/"HEXPR",/*7*/ "LEXPR",/*8*/ "PA",/*9*/ "FDECL", /*10*/"ARG",
        /*11*/ "MOREARGS",/*12*/ "BLOCK",/*13*/ "STMT",/*14*/ "COND",/*15*/ "ELSE",
        /*16*/ "RETURN",/*17*/ "CDECL",/*18*/ "ODECL",
        // Terminal
        /*19*/"vtype",/*20*/"id",/*21*/"semi",
        /*22*/"assign",/*23*/"literal",/*24*/ "character",/*25*/"boolstr",/*26*/"addsub",/*27*/"lparen",/*28*/"rparen",
        /*29*/ "multdiv",/*30*/ "num",/*31*/ "lbrace", /*32*/ "rbrace",/*33*/ "comma",/*34*/"if",/*35*/"while",/*36*/ "comp",
        /*37*/ "else",/*38*/ "return",/*39*/"class", /*40*/ "$",/*41*/ "eof"
    };
    vector<int> word_num;
    for (int i = 0; i < words.size(); i++)
        for (int j = 0; j < 42; j++) {
            if (words.at(i) == rules[j]) {
                word_num.push_back(j);
                break;
            }
            if (j == 41) {
                cerr << "no match SLR - " << words.at(i) << endl;
                return EXIT_FAILURE;
            }
        }
    int arr[40] = { 0, 1, 1, 1, -1, 2, 2, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 10, -10, 11, -11, 12, -12, 13, 13, 13,
                    13, 14, 14, 15, -15, 16, 17, 18, 18, -18 };
    int CFG_tree[20][4][10] = {
            {{1},},
            {{2,  1},{9,  1},{17, 1},{41}},
            {{19, 20, 21},{19, 3,  21}},
            {{20, 22, 4}},
            {{5},{23},{24},{25}},
            {{6,  26, 5},{6},{27, 5,  28}},
            {{8},{8,  29, 6}},
            {{5}},
            {{20},{30}},
            {{19, 20, 27, 10, 28, 31, 12, 16, 32}},
            {{19, 20, 11},{41}},
            {{33, 19, 20, 11}, {41}},
            {{13, 12},{41}},
            {{2},{3,  21}, {34, 27, 14, 28, 31, 12, 32, 15}, {35, 27, 14, 28, 31, 12, 32}},
            {{25, 36, 14},{25}},
            {{37, 31, 12, 32}, {41}},
            {{38, 4,  21}},
            {{39, 20, 31, 18, 32}},
            {{2,  18},{9,  18}, {41}}
    };
    stack.push(0);
    int size, spl, splitter = 0, state = 0, x, k;
    while (true) {
        spl = word_num.at(splitter);
        x = ACTTable[state][spl - 19];
        if (x == 999 && word_num.at(0) == 1) {
            for (int i = 0; i < word_num.size(); i++)
                cout << rules[word_num.at(i)] << " ";
            cout << endl << endl;
            cerr << "INPUT ACCEPT !" << endl;
            return 0;
        }
        else if (x > 0) {
            stack.push(x);
            state = x;
            splitter++;
        }
        else {
            for (int i = 0; i < word_num.size(); i++)
                cout << rules[word_num.at(i)] << " ";
            cout << endl;
            x = -x;
            x = arr[x];
            if (x < 0) {
                x = -x;
                word_num.insert(word_num.begin() + splitter, x);
                state = GOTOTable[stack.top()][x];
                stack.push(state);
                splitter++;
                continue;
            }
            for (int i = 3; i >= 0; i--) {
                if (CFG_tree[x][i][0] == 0) continue;
                size = 0;
                for (int j = 9; j >= 0; j--) {
                    k = CFG_tree[x][i][j];
                    if (k == 0) continue;
                    else if (k != word_num.at(splitter - size - 1)) {
                        size = 0;
                        break;
                    }
                    else size++;
                }
                if (size) {
                    for (int j = size; j > 0; j--) {
                        word_num.erase(word_num.begin() + splitter - j);
                        splitter--;
                        stack.pop();
                    }
                    word_num.insert(word_num.begin() + splitter, x);
                    break;
                }
            }
            state = GOTOTable[stack.top()][x];
            stack.push(state);
            splitter++;
        }
    }
}