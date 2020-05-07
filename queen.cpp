#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define Ex_Dis 2
float all_distance, Min_all_distance = 10000;
int min_start_loca[7];
int min_end_loca[7];
int start_location = 57;
int end_location = 57;


//int chess_location[8]={2,5,8,13,30,31,32,36};
//int chess_location[8]={17,29,37,41,42,49,52,53};
//int chess_location[8]={12,19,20,21,22,28,36,44};
//int chess_location[8]={9,10,17,24,49,57,58,64};
int chess_location[8]={24,32,37,38,42,47,55,58};


//int chess_location[8] = {1,2,3,9,10,34,42,43};
//int chess_location[8] = {5,6,9,16,27,39,42,60};
//int chess_location[8] = { 18,29,37,41,42,49,52,61 };
//int chess_location[8] = { 12,15,19,20,21,28,36,52 };
//int chess_location[8] = { 2,5,8,12,30,32,36,47 };
//int chess_location[8] = {1,8,13,21,31,40,46,58};
int chess_notmove[8];
static int gEightQueen[8] = { 0 }, gCount = 0;
int map[8][8];
int result[8];
int Notmove[92];
int Max_Notmove;
int Max_Notmove_times = 1;
int start_loca_set[18][7] = {
    { 8,15,22,29,36,43,57 },
    { 1,10,19,28,37,46,64 },

    { 57,49,41,33,25,17,9 },
    { 58,50,42,34,26,18,10 },
    { 59,51,43,35,27,19,11 },
    { 4,12,20,28,36,44,52 },
    { 5,13,21,29,37,45,53 },
    { 6,14,22,30,38,46,54 },
    { 7,15,23,31,39,47,55 },
    { 8,16,24,32,40,48,56 },
    { 8,7,6,5,4,3,2 },
    { 16,15,14,13,12,11,10 },
    { 17,18,19,20,21,22,23 },
    { 32,31,30,29,28,27,26 },
    { 40,39,38,37,36,35,34 },
    { 48,47,46,45,44,43,42 },
    { 56,55,54,53,52,51,50 },
    { 64,63,62,61,60,59,58 }
};
int end_loca_set[18][7] = {
    { 24,13,30,47,35,60,1 },
    { 3,26,20,14,45,40,57 },

    { 60,50,47,35,30,13,24 },
    { 60,55,45,35,25,22,16 },
    { 61,50,46,33,31,20,16 },
    { 3,14,18,31,37,41,56 },
    { 3,15,18,32,38,44,49 },
    { 4,15,19,32,34,45,49 },
    { 5,10,20,30,40,43,49 },
    { 5,15,18,30,35,52,41 },
    { 32,15,54,21,44,34,59 },
    { 32,55,38,21,4,43,58 },
    { 33,10,43,4,53,30,63 },
    { 40,55,14,45,20,3,58 },
    { 48,23,54,13,28,59,2 },
    { 32,55,22,61,12,35,2 },
    { 40,15,30,45,60,19,2 },
    { 40,55,14,45,20,26,3 }
};
int solution[92][8] = {
    { 1,13,24,30,35,47,50,60 },   //0
    { 1,14,24,27,39,44,50,61 },   //1
    { 1,15,20,30,40,42,53,59 },   //2
    { 1,15,21,32,34,44,54,59 },   //3
    { 2,12,22,32,35,41,55,61 },   //4
    { 2,13,23,25,35,48,54,60 },   //5
    { 2,13,23,28,33,48,54,59 },   //6
    { 2,14,17,31,36,48,51,61 },   //7
    { 2,14,24,27,33,44,55,61 },   //8
    { 2,15,19,30,40,45,49,60 },   //9
    { 2,15,21,32,33,44,54,59 },   //10
    { 2,16,22,25,35,45,55,60 },   //11
    { 3,9,23,29,40,42,52,62 },   //12
    { 3,13,18,32,33,47,52,62 },   //13
    { 3,13,18,32,38,44,55,57 },   //14
    { 3,13,23,25,36,42,56,62 },   //15
    { 3,13,24,28,33,47,50,62 },   //16
    { 3,14,18,29,40,41,55,60 },   //17
    { 3,14,18,31,33,44,56,61 },   //18
    { 3,14,18,31,37,41,56,60 },   //19
    { 3,14,20,25,40,45,55,58 },   //20
    { 3,14,20,26,40,45,55,57 },   //21
    { 3,14,24,25,36,47,53,58 },   //22
    { 3,14,24,25,37,47,50,60 },   //23
    { 3,14,24,26,36,41,55,61 },   //24
    { 3,15,18,32,37,41,52,62 },   //25
    { 3,15,18,32,38,44,49,61 },   //26
    { 3,16,20,31,33,46,50,61 },   //27
    { 4,9,21,32,34,47,51,62 },   //28
    { 4,9,21,32,38,43,55,58 },   //29
    { 4,10,21,32,38,41,51,63 },   //30
    { 4,10,23,27,38,48,49,61 },   //31
    { 4,10,23,27,38,48,53,57 },   //32
    { 4,10,23,29,33,48,54,59 },   //33
    { 4,10,24,29,39,41,51,62 },   //34
    { 4,10,24,30,33,43,53,63 },   //35
    { 4,14,17,29,34,48,51,63 },   //36
    { 4,14,24,26,39,41,51,61 },   //37
    { 4,14,24,27,33,47,53,58 },   //38
    { 4,15,17,32,37,42,54,59 },   //39
    { 4,15,19,32,34,45,49,62 },   //40
    { 4,15,21,26,38,41,51,64 },   //41
    { 4,15,21,27,33,46,56,58 },   //42
    { 4,16,17,27,38,42,55,61 },   //43
    { 4,16,17,29,39,42,54,59 },   //44
    { 4,16,21,27,33,47,50,62 },   //45
    { 5,9,20,30,40,42,55,59 },   //46
    { 5,9,24,28,34,47,51,62 },   //47
    { 5,9,24,30,35,47,50,60 },   //48
    { 5,10,20,30,40,43,49,63 },   //49
    { 5,10,20,31,35,48,54,57 },   //50
    { 5,10,22,25,39,44,56,59 },   //51
    { 5,10,24,25,36,47,51,62 },   //52
    { 5,11,17,30,40,42,52,63 },   //53
    { 5,11,17,31,34,48,54,60 },   //54
    { 5,11,24,28,39,41,54,58 },   //55
    { 5,15,17,27,40,46,52,58 },   //56
    { 5,15,17,28,34,48,54,59 },   //57
    { 5,15,18,28,40,41,51,62 },   //58
    { 5,15,18,30,35,41,52,64 },   //59
    { 5,15,18,30,35,41,56,60 },   //60
    { 5,15,20,25,35,48,54,58 },   //61
    { 5,16,20,25,35,46,50,63 },   //62
    { 5,16,20,25,39,42,54,59 },   //63
    { 6,9,21,26,40,43,55,60 },   //64
    { 6,10,23,25,35,45,56,60 },   //65
    { 6,10,23,25,36,48,53,59 },   //66
    { 6,11,17,31,37,48,50,60 },   //67
    { 6,11,17,32,36,42,55,61 },   //68
    { 6,11,17,32,37,42,52,63 },   //69
    { 6,11,21,31,33,44,50,64 },   //70
    { 6,11,21,32,33,44,50,63 },   //71
    { 6,11,23,26,36,48,49,61 },   //72
    { 6,11,23,26,40,45,49,60 },   //73
    { 6,11,23,28,33,48,50,61 },   //74
    { 6,12,17,29,40,42,55,59 },   //75
    { 6,12,18,32,37,47,49,59 },   //76
    { 6,12,23,25,35,45,50,64 },   //77
    { 6,12,23,25,40,42,53,59 },   //78
    { 6,16,18,28,33,47,53,59 },   //79
    { 7,9,19,32,38,44,50,61 },   //80
    { 7,10,20,25,40,45,51,62 },   //81
    { 7,10,22,27,33,44,56,61 },   //82
    { 7,11,17,30,40,45,50,60 },   //83
    { 7,11,24,26,37,41,54,60 },   //84
    { 7,12,18,29,40,41,51,62 },   //85
    { 7,12,18,32,38,41,51,61 },   //86
    { 7,13,19,25,38,48,50,60 },   //87
    { 8,10,20,25,39,45,51,62 },   //88
    { 8,10,21,27,33,47,52,62 },   //89
    { 8,11,17,30,34,45,55,60 },   //90
    { 8,12,17,27,38,42,55,61 }   //91
};
void print()//输出每一种情况下棋盘中皇后的摆放情况
{
    //for (int i = 0; i < 8; i++)
    //{
    //	int inner;
    //	for (inner = 0; inner < gEightQueen[i]; inner++)
    //		cout << "0";
    //	cout << "#";
    //	for (inner = gEightQueen[i] + 1; inner < 8; inner++)
    //		cout << "0";
    //	cout << endl;
    //}
    //cout << "==========================\n";
    static int a = 0;
    cout << "{";
    for (int i = 0; i < 8; i++)
    {
        cout << i * 8 + gEightQueen[i] + 1;
        if (i != 7)
            cout << ",";
        else
            cout << "},   //" << a << endl;
    }
    a++;
}
int check_pos_valid(int loop, int value)//检查是否存在有多个皇后在同一行/列/对角线的情况
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = gEightQueen[index];
        if (value == data)
            return 0;
        if ((index + data) == (loop + value))
            return 0;
        if ((index - data) == (loop - value))
            return 0;
    }
    return 1;
}
void eight_queen(int index)			//计算八皇后所有可能的解
{
    int loop;
    for (loop = 0; loop < 8; loop++)
    {
        if (check_pos_valid(index, loop))
        {
            gEightQueen[index] = loop;
            if (7 == index)
            {
                gCount++, print();
                gEightQueen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            gEightQueen[index] = 0;
        }
    }
}
void init()
{
    all_distance = 0;
    Min_all_distance = 10000;
    for (int i = 0; i < 7; i++)
    {
        min_start_loca[i] = 0;
        min_end_loca[i] = 0;
    }
    start_location = 57;
    end_location = 57;
    for (int i = 0; i<92; i++)
        Notmove[i] = 0;
    Max_Notmove = 0;
    Max_Notmove_times = 1;
}
void check()
{
    int i, j, count_1;
    for (int times = 0; times < 92; times++)
    {
        i = 0;
        j = 0;
        count_1 = 0;
        while (1)
        {
            if (chess_location[i] < solution[times][j])
            {
                i++;
            }
            else if (chess_location[i] > solution[times][j])
            {
                j++;
            }
            else
            {
                count_1++;
                i++;
                j++;
            }
            if (i > 7 || j > 7)
            {
                Notmove[times] = count_1;
                if (Max_Notmove < count_1)
                {
                    Max_Notmove = count_1;
                    Max_Notmove_times = 1;
                }
                else if (Max_Notmove == count_1)
                    Max_Notmove_times++;
                break;
            }
        }
    }
}
int get_se_dis(int position)		//上方不能进场
{
    int b, c, d;
    b = 7 - (position - 1) / 8;
    c = (position - 1) % 8;
    d = 7 - (position - 1) % 8;
    if (b <= c && b <= d)
    {
        return b;
    }
    else if (c <= b && c <= d)
    {
        return c;
    }
    else if (d <= b && d <= c)
    {
        return d;
    }
}
void get_se_position(int position, int SE_choose)		//0为Start,1为End
{
    int b, c, d;
    int *pointer;
    if (SE_choose == 0)
        pointer = &start_location;
    else
        pointer = &end_location;
    b = 7 - (position - 1) / 8;
    c = (position - 1) % 8;
    d = 7 - (position - 1) % 8;
    if (b <= c && b <= d)
    {
        *pointer = position + b * 8;
    }
    else if (c <= b && c <= d)
    {
        *pointer = position - c;
    }
    else if (d <= b && d <= c)
    {
        *pointer = position + d;
    }
    else
        cout<<"SE"<<SE_choose<<"Error!"<<endl;
}
float get_twopoint_dis(int start, int end)
{
    int x, y = 0;
    float Extra_dis = 0;
    if (start < 9)
    {
        start += 8;
        Extra_dis += Ex_Dis;
    }
    if (end < 9)
    {
        end += 8;
        Extra_dis += Ex_Dis;
    }
    x = abs((start - 1) / 8 - (end - 1) / 8);
    y = abs((start - 1) % 8 - (end - 1) % 8);
    return sqrtf(x*x + y * y) + Extra_dis;
}
int check_move(int* start_loca, int* end_loca, int loca, int j)
{
    for (int i = 0; i < Max_Notmove; i++)
    {
        if (chess_notmove[i] == loca)
        {
            return 1;
        }
    }
    for (int i = 0; i < j; i++)
    {
        if (end_loca[i] == loca)
        {
            return 1;
        }
    }
    for (int i = j + 1; i < 8 - Max_Notmove; i++)
    {
        if (start_loca[i] == loca)
        {
            return 1;
        }
    }
    return 0;
}
void one_solution()
{
    float dis1;
    int a = 0, b = 0;
    int start_loca[7];
    int end_loca[7];
    while (b < Max_Notmove_times)
    {
        if (Notmove[a] == Max_Notmove)
        {
            //处理
            int i = 0, j = 0, k = 0, l = 0, pointer = 0;
            while (1)
            {
                if (chess_location[i] < solution[a][j])
                {
                    start_loca[k] = chess_location[i];
                    i++;
                    k++;
                }
                else if (chess_location[i] > solution[a][j])
                {
                    end_loca[l] = solution[a][j];
                    j++;
                    l++;
                }
                else
                {
                    chess_notmove[pointer] = chess_location[i];
                    i++;
                    j++;
                    pointer++;
                }
                if (i>7 && j>7)
                    break;
                if (i > 7)
                {
                    while (j <= 7)
                    {
                        end_loca[l] = solution[a][j];
                        l++;
                        j++;
                    }
                    break;
                }
                if (j > 7)
                {
                    while (i <= 7)
                    {
                        start_loca[k] = chess_location[i];
                        k++;
                        i++;
                    }
                    break;
                }
            }
            //得到需要移动的棋子
            do
            {
                do
                {
                    int k = 0, check_loca = 0, break_flag = 0;
                    for (int j = 0; j < 8 - Max_Notmove; j++)
                    {
                        check_loca = start_loca[j];
                        if (check_loca > 8)		//UP
                        {
                            if (check_move(start_loca, end_loca, check_loca - 8, j) == 0)
                            {
                                continue;
                            }
                        }
                        if (check_loca < 57)		//down
                        {
                            if (check_move(start_loca, end_loca, check_loca + 8, j) == 0)
                            {
                                continue;
                            }
                        }
                        if ((check_loca % 8)>0)		//right
                        {
                            if (check_move(start_loca, end_loca, check_loca + 1, j) == 0)
                            {
                                continue;
                            }
                        }
                        if ((check_loca % 8) != 1)		//left
                        {
                            if (check_move(start_loca, end_loca, check_loca - 1, j) == 0)
                            {
                                continue;
                            }
                        }
                        break_flag = 1;
                        break;
                    }
                    if (break_flag == 0)
                    {
                        dis1 = get_se_dis(start_loca[0]);
                        for (int i = 0; i < 8 - Max_Notmove; i++)
                        {
                            dis1 += get_twopoint_dis(start_loca[i], end_loca[i]);
                        }
                        for (int i = 0; i < 7 - Max_Notmove; i++)
                        {
                            dis1 += get_twopoint_dis(end_loca[i], start_loca[i + 1]);
                        }
                        dis1 += get_se_dis(end_loca[7 - Max_Notmove]);
                        if (Min_all_distance > dis1)
                        {
                            Min_all_distance = dis1;
                            for (int i = 0; i < 8 - Max_Notmove; i++)
                            {
                                min_start_loca[i] = start_loca[i];
                                min_end_loca[i] = end_loca[i];
                            }
                        }
                    }
                } while (next_permutation(start_loca, start_loca + 8 - Max_Notmove));
            } while (next_permutation(end_loca, end_loca + 8 - Max_Notmove));
            b++;
        }
        a++;
    }
}
int main(int argc, char*argv[])
{
    check();
    if (Max_Notmove < 2)		//7!情况
    {
        if (chess_location[1] - chess_location[0] == 7)
        {
            for (int i = 0; i < 7; i++)
            {
                min_start_loca[i] = start_loca_set[0][i];
                min_end_loca[i] = end_loca_set[0][i];
            }
        }
        else if (chess_location[1] - chess_location[0] == 9)
        {
            for (int i = 0; i < 7; i++)
            {
                min_start_loca[i] = start_loca_set[1][i];
                min_end_loca[i] = end_loca_set[1][i];
            }
        }
        else if (chess_location[7] - chess_location[0] > 10)
        {
            for (int i = 0; i < 7; i++)
            {
                min_start_loca[i] = start_loca_set[(chess_location[0] - 1) % 8 + 2][i];
                min_end_loca[i] = end_loca_set[(chess_location[0] - 1) % 8 + 2][i];
            }
        }
        else
        {
            for (int i = 0; i < 7; i++)
            {
                min_start_loca[i] = start_loca_set[(chess_location[0] - 1) / 8 + 10][i];
                min_end_loca[i] = end_loca_set[(chess_location[0] - 1) / 8 + 10][i];
            }
        }
        Min_all_distance = get_se_dis(min_start_loca[0]);
        for (int i = 0; i < 8 - Max_Notmove; i++)
        {
            Min_all_distance += get_twopoint_dis(min_start_loca[i], min_end_loca[i]);
        }
        for (int i = 0; i < 7 - Max_Notmove; i++)
        {
            Min_all_distance += get_twopoint_dis(min_end_loca[i], min_start_loca[i + 1]);
        }
        Min_all_distance += get_se_dis(min_end_loca[6]);
        get_se_position(min_start_loca[0], 0);
        get_se_position(min_end_loca[6], 1);
        cout << "当前棋子分布：{";
        for (int i = 0; i < 7; i++)
        {
            cout << chess_location[i] << ",";
        }
        cout << chess_location[7] << "}" << endl;
        cout << "平台起始位置：" << start_location << endl;
        cout << "平台终止位置：" << end_location << endl;
        cout << "最短运动距离：" << Min_all_distance * 50 << "cm" << endl;
        cout << "平台搬运路径：" << start_location << " >> ";
        for (int i = 0; i < 8 - Max_Notmove; i++)
        {
            cout << min_start_loca[i] << "->" << min_end_loca[i] << " >> ";
        }
        cout << end_location << endl << endl;
        return 0;
    }
    one_solution();
    get_se_position(min_start_loca[0], 0);
    get_se_position(min_end_loca[7 - Max_Notmove], 1);
    cout << "当前棋子分布：{";
    for (int i = 0; i < 7; i++)
    {
        cout << chess_location[i] << ",";
    }
    cout << chess_location[7] << "}" << endl;
    cout << "平台起始位置：" << start_location << endl;
    cout << "平台终止位置：" << end_location << endl;
    cout << "最短运动距离：" << Min_all_distance * 50 << "cm" << endl;
    cout << "平台搬运路径：" << start_location << " >> ";
    for (int i = 0; i < 8 - Max_Notmove; i++)
    {
        cout << min_start_loca[i] << "->" << min_end_loca[i] << " >> ";
    }
    cout << end_location << endl << endl;
    system("pause");
}
//int main()
//{
//	int arr1[4] = { 1,2,3,0 };
//	cout << "用next_permutation对1 2 3的全排列" << endl;
//	do
//	{
//		cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << '\n';
//	} while (next_permutation(arr1, arr1 + 3));
//}



