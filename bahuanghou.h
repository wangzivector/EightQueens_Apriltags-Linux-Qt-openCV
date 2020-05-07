#ifndef BAHUANGHOU_H
#define BAHUANGHOU_H

class bahuanghou
{
public:
    explicit bahuanghou(void);
    float all_distance;
    float Min_all_distance;
    int start_location;
    int end_location;
    unsigned int  min_start_loca[7];
    unsigned int  min_end_loca[7];
    unsigned int  chess_location[8];
    int Max_Notmove;
    int movestep;
    void init();
    int bahuanghou_figure(unsigned int *);

private:
    int i;
    void swap(int *s1, int *s2);
    void reverse(int *s, int* e);
    int next_permutation(int *start, int *end);
    void check();
    float get_twopoint_dis(int start, int end);
    int check_move(int* start_loca, int* end_loca, int loca, int j);
    void one_solution();
    unsigned int abs(int);
//    int chess_notmove[8];
//    int map[8][8];
//    int result[8];
//    int Notmove[92];
//    int Max_Notmove;
//    int Max_Notmove_times;
//    int start_loca_set[18][7];
//    int end_loca_set[18][7];
//    int solution[92][8];
};

#endif
