#include <stdio.h>
#include <stdint.h>

#define MOD_NUM (1000000000U)
#define MAX_N   (0x0DE0B6B3A7640000UL)  /* 10^18 */

#define BIT01_64    (0x0000000000000001UL)
#define BIT02_64    (0x0000000000000002UL)
#define BIT03_64    (0x0000000000000004UL)
#define BIT04_64    (0x0000000000000008UL)
#define BIT05_64    (0x0000000000000010UL)
#define BIT06_64    (0x0000000000000020UL)
#define BIT07_64    (0x0000000000000040UL)
#define BIT08_64    (0x0000000000000080UL)
#define BIT09_64    (0x0000000000000100UL)
#define BIT10_64    (0x0000000000000200UL)
#define BIT11_64    (0x0000000000000400UL)
#define BIT12_64    (0x0000000000000800UL)
#define BIT13_64    (0x0000000000001000UL)
#define BIT14_64    (0x0000000000002000UL)
#define BIT15_64    (0x0000000000004000UL)
#define BIT16_64    (0x0000000000008000UL)
#define BIT17_64    (0x0000000000010000UL)
#define BIT18_64    (0x0000000000020000UL)
#define BIT19_64    (0x0000000000040000UL)
#define BIT20_64    (0x0000000000080000UL)
#define BIT21_64    (0x0000000000100000UL)
#define BIT22_64    (0x0000000000200000UL)
#define BIT23_64    (0x0000000000400000UL)
#define BIT24_64    (0x0000000000800000UL)
#define BIT25_64    (0x0000000001000000UL)
#define BIT26_64    (0x0000000002000000UL)
#define BIT27_64    (0x0000000004000000UL)
#define BIT28_64    (0x0000000008000000UL)
#define BIT29_64    (0x0000000010000000UL)
#define BIT30_64    (0x0000000020000000UL)
#define BIT31_64    (0x0000000040000000UL)
#define BIT32_64    (0x0000000080000000UL)
#define BIT33_64    (0x0000000100000000UL)
#define BIT34_64    (0x0000000200000000UL)
#define BIT35_64    (0x0000000400000000UL)
#define BIT36_64    (0x0000000800000000UL)
#define BIT37_64    (0x0000001000000000UL)
#define BIT38_64    (0x0000002000000000UL)
#define BIT39_64    (0x0000004000000000UL)
#define BIT40_64    (0x0000008000000000UL)
#define BIT41_64    (0x0000010000000000UL)
#define BIT42_64    (0x0000020000000000UL)
#define BIT43_64    (0x0000040000000000UL)
#define BIT44_64    (0x0000080000000000UL)
#define BIT45_64    (0x0000100000000000UL)
#define BIT46_64    (0x0000200000000000UL)
#define BIT47_64    (0x0000400000000000UL)
#define BIT48_64    (0x0000800000000000UL)
#define BIT49_64    (0x0001000000000000UL)
#define BIT50_64    (0x0002000000000000UL)
#define BIT51_64    (0x0004000000000000UL)
#define BIT52_64    (0x0008000000000000UL)
#define BIT53_64    (0x0010000000000000UL)
#define BIT54_64    (0x0020000000000000UL)
#define BIT55_64    (0x0040000000000000UL)
#define BIT56_64    (0x0080000000000000UL)
#define BIT57_64    (0x0100000000000000UL)
#define BIT58_64    (0x0200000000000000UL)
#define BIT59_64    (0x0400000000000000UL)
#define BIT60_64    (0x0800000000000000UL)
#define BIT61_64    (0x1000000000000000UL)
#define BIT62_64    (0x2000000000000000UL)
#define BIT63_64    (0x4000000000000000UL)
#define BIT64_64    (0x8000000000000000UL)


static const uint64_t pow_2_arr[64] = { BIT01_64, BIT02_64, BIT03_64, BIT04_64, BIT05_64, BIT06_64, BIT07_64, BIT08_64, BIT09_64, BIT10_64, BIT11_64, BIT12_64, BIT13_64, BIT14_64, BIT15_64, BIT16_64,
                                        BIT17_64, BIT18_64, BIT19_64, BIT20_64, BIT21_64, BIT22_64, BIT23_64, BIT24_64, BIT25_64, BIT26_64, BIT27_64, BIT28_64, BIT29_64, BIT30_64, BIT31_64, BIT32_64,
                                        BIT33_64, BIT34_64, BIT35_64, BIT36_64, BIT37_64, BIT38_64, BIT39_64, BIT40_64, BIT41_64, BIT42_64, BIT43_64, BIT44_64, BIT45_64, BIT46_64, BIT47_64, BIT48_64,
                                        BIT49_64, BIT50_64, BIT51_64, BIT52_64, BIT53_64, BIT54_64, BIT55_64, BIT56_64, BIT57_64, BIT58_64, BIT59_64, BIT60_64, BIT61_64, BIT62_64, BIT63_64, BIT64_64
};

/* フィボナッチ数列のベース行列の2の累乗をMOD_NUM (1000000000U)で割った余りの配列 */
static const uint64_t fibonacci_base_arr[64][2][2] = {  {{1UL, 1UL}, {1UL, 0UL}},/*1*/
                                                        {{2UL, 1UL}, {1UL, 1UL}},/*2*/
                                                        {{5UL, 3UL}, {3UL, 2UL}},/*3*/
                                                        {{34UL, 21UL}, {21UL, 13UL}},/*4*/
                                                        {{1597UL, 987UL}, {987UL, 610UL}},/*5*/
                                                        {{3524578UL, 2178309UL}, {2178309UL, 1346269UL}},/*6*/
                                                        {{680177565UL, 209857723UL}, {209857723UL, 470319842UL}},/*7*/
                                                        {{832073954UL, 150424261UL}, {150424261UL, 681649693UL}},/*8*/
                                                        {{222590237UL, 958199867UL}, {958199867UL, 264390370UL}},/*9*/
                                                        {{726533858UL, 858979269UL}, {858979269UL, 867554589UL}},/*10*/
                                                        {{392138525UL, 925405243UL}, {925405243UL, 466733282UL}},/*11*/
                                                        {{561064674UL, 262684101UL}, {262684101UL, 298380573UL}},/*12*/
                                                        {{328904477UL, 66917947UL}, {66917947UL, 261986530UL}},/*13*/
                                                        {{621338338UL, 89202629UL}, {89202629UL, 532135709UL}},/*14*/
                                                        {{289113885UL, 475669563UL}, {475669563UL, 813444322UL}},/*15*/
                                                        {{664404194UL, 505753541UL}, {505753541UL, 158650653UL}},/*16*/
                                                        {{238828317UL, 307463227UL}, {307463227UL, 931365090UL}},/*17*/
                                                        {{958306018UL, 130344389UL}, {130344389UL, 827961629UL}},/*18*/
                                                        {{878799645UL, 38682683UL}, {38682683UL, 840116962UL}},/*19*/
                                                        {{16204514UL, 212016581UL}, {212016581UL, 804187933UL}},/*20*/
                                                        {{892905757UL, 691163707UL}, {691163707UL, 201742050UL}},/*21*/
                                                        {{757724898UL, 145540549UL}, {145540549UL, 612184349UL}},/*22*/
                                                        {{452331805UL, 888556603UL}, {888556603UL, 563775202UL}},/*23*/
                                                        {{549457634UL, 424417221UL}, {424417221UL, 125040413UL}},/*24*/
                                                        {{42240797UL, 677667387UL}, {677667387UL, 364573410UL}},/*25*/
                                                        {{334602978UL, 652167109UL}, {652167109UL, 682435869UL}},/*26*/
                                                        {{947886365UL, 588683323UL}, {588683323UL, 359203042UL}},/*27*/
                                                        {{731235554UL, 570859461UL}, {570859461UL, 160376093UL}},/*28*/
                                                        {{646897437UL, 227742267UL}, {227742267UL, 419155170UL}},/*29*/
                                                        {{175468258UL, 459440069UL}, {459440069UL, 716028189UL}},/*30*/
                                                        {{568279325UL, 122934843UL}, {122934843UL, 445344482UL}},/*31*/
                                                        {{845890274UL, 574607301UL}, {574607301UL, 271282973UL}},/*32*/
                                                        {{10299677UL, 208076347UL}, {208076347UL, 802223330UL}},/*33*/
                                                        {{527168738UL, 150015429UL}, {150015429UL, 377153309UL}},/*34*/
                                                        {{262566685UL, 834863163UL}, {834863163UL, 427703522UL}},/*35*/
                                                        {{6253794UL, 340684741UL}, {340684741UL, 665569053UL}},/*36*/
                                                        {{689631517UL, 628077627UL}, {628077627UL, 61553890UL}},/*37*/
                                                        {{777672418UL, 865589189UL}, {865589189UL, 912083229UL}},/*38*/
                                                        {{831644445UL, 94900283UL}, {94900283UL, 736744162UL}},/*39*/
                                                        {{612838114UL, 658275781UL}, {658275781UL, 954562333UL}},/*40*/
                                                        {{822236957UL, 388674107UL}, {388674107UL, 433562850UL}},/*41*/
                                                        {{908867298UL, 556497349UL}, {556497349UL, 352369949UL}},/*42*/
                                                        {{817848605UL, 415558203UL}, {415558203UL, 402290402UL}},/*43*/
                                                        {{781035234UL, 159124421UL}, {159124421UL, 621910813UL}},/*44*/
                                                        {{108019997UL, 423113787UL}, {423113787UL, 684906210UL}},/*45*/
                                                        {{501361378UL, 255315909UL}, {255315909UL, 246045469UL}},/*46*/
                                                        {{738555165UL, 534628923UL}, {534628923UL, 203926242UL}},/*47*/
                                                        {{56317154UL, 571934661UL}, {571934661UL, 484382493UL}},/*48*/
                                                        {{287844637UL, 309764667UL}, {309764667UL, 978079970UL}},/*49*/
                                                        {{971282658UL, 334460869UL}, {334460869UL, 636821789UL}},/*50*/
                                                        {{623780125UL, 786384443UL}, {786384443UL, 837395682UL}},/*51*/
                                                        {{537435874UL, 112770501UL}, {112770501UL, 424665373UL}},/*52*/
                                                        {{557934877UL, 636914747UL}, {636914747UL, 921020130UL}},/*53*/
                                                        {{919079138UL, 107788229UL}, {107788229UL, 811290909UL}},/*54*/
                                                        {{217779485UL, 880776763UL}, {880776763UL, 337002722UL}},/*55*/
                                                        {{327623394UL, 451455941UL}, {451455941UL, 876167453UL}},/*56*/
                                                        {{960274717UL, 599572027UL}, {599572027UL, 360702690UL}},/*57*/
                                                        {{670318818UL, 536193989UL}, {536193989UL, 134124829UL}},/*58*/
                                                        {{604649245UL, 10637883UL}, {10637883UL, 594011362UL}},/*59*/
                                                        {{33791714UL, 293974981UL}, {293974981UL, 739816733UL}},/*60*/
                                                        {{389008157UL, 508264507UL}, {508264507UL, 880743650UL}},/*61*/
                                                        {{288489698UL, 197214149UL}, {197214149UL, 91275549UL}},/*62*/
                                                        {{417925405UL, 6879803UL}, {6879803UL, 411045602UL}},/*63*/
                                                        {{833732834UL, 220871621UL}, {220871621UL, 612861213UL}}/*64*/
};

unsigned int fibonacci_N_mod_10_9 (uint64_t inpt_N);
void pow2_arry2_2 (uint64_t out_arr[][2], uint64_t inpt_arr[][2], uint64_t mod_num);
void innr_prd_arry2_2 (uint64_t out_arr[][2], uint64_t inpt_arr_A[][2], uint64_t inpt_arr_B[][2], uint64_t mod_num);

int main(void)
{
    unsigned int ans;
    uint64_t inpt_N;


    /* get input */
    (void)scanf("%lu\n", &inpt_N);

    ans = fibonacci_N_mod_10_9(inpt_N);

    printf("%u\n", ans);

    return 0;
}

unsigned int fibonacci_N_mod_10_9 (uint64_t inpt_N)
{
    int i;
    unsigned int ret;
    uint64_t out_arr[2][2];
    uint64_t tmp_arr[2][2] = {{1UL, 0UL},{0UL, 1UL}};

    for(i = 0; (pow_2_arr[i] <= inpt_N) && (i < 64); i++)
    {
        if ((pow_2_arr[i] & inpt_N) != 0UL)
        {
            innr_prd_arry2_2(out_arr, tmp_arr, fibonacci_base_arr[i], MOD_NUM);
            tmp_arr[0][0] = out_arr[0][0];
            tmp_arr[0][1] = out_arr[0][1];
            tmp_arr[1][0] = out_arr[1][0];
            tmp_arr[1][1] = out_arr[1][1];
        }
        else{/*nothing*/}
    }

    ret = (unsigned int)out_arr[0][1];

    return ret;
}

void pow2_arry2_2 (uint64_t out_arr[][2], uint64_t inpt_arr[][2], uint64_t mod_num) /*2×2行列の2乗を計算し、mod_numで割った余りを出力する*/
{
    out_arr[0][0] = (inpt_arr[0][0] * inpt_arr[0][0]) + (inpt_arr[0][1] * inpt_arr[1][0]);
    out_arr[0][1] = (inpt_arr[0][0] * inpt_arr[0][1]) + (inpt_arr[0][1] * inpt_arr[1][1]);
    out_arr[1][0] = (inpt_arr[0][0] * inpt_arr[1][0]) + (inpt_arr[1][0] * inpt_arr[1][1]);
    out_arr[1][1] = (inpt_arr[1][0] * inpt_arr[0][1]) + (inpt_arr[1][1] * inpt_arr[1][1]);

    out_arr[0][0] %= mod_num;
    out_arr[0][1] %= mod_num;
    out_arr[1][0] %= mod_num;
    out_arr[1][1] %= mod_num;

    return;
}

void innr_prd_arry2_2 (uint64_t out_arr[][2], uint64_t inpt_arr_A[][2], uint64_t inpt_arr_B[][2], uint64_t mod_num) /*2×2行列の内積ABを計算し、mod_numで割った余りを出力する*/
{
    out_arr[0][0] = (inpt_arr_A[0][0] * inpt_arr_B[0][0]) + (inpt_arr_A[0][1] * inpt_arr_B[1][0]);
    out_arr[0][1] = (inpt_arr_A[0][0] * inpt_arr_B[0][1]) + (inpt_arr_A[0][1] * inpt_arr_B[1][1]);
    out_arr[1][0] = (inpt_arr_A[1][0] * inpt_arr_B[0][0]) + (inpt_arr_A[1][1] * inpt_arr_B[1][0]);
    out_arr[1][1] = (inpt_arr_A[1][0] * inpt_arr_B[0][1]) + (inpt_arr_A[1][1] * inpt_arr_B[1][1]);

    out_arr[0][0] %= mod_num;
    out_arr[0][1] %= mod_num;
    out_arr[1][0] %= mod_num;
    out_arr[1][1] %= mod_num;

    return;
}
