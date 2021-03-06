#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

//<2016/10/26-nickygao, [LV3][MISC][COMMON][BSP][][]Update NTC table for battery
#if 0
// <<< 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table
#define LG_BL_45F1F 1
#else
#define LG_BL_45F1F 0
#define BAT_NTC_68 1
#endif
//<2016/10/26-nickygao
//#define BAT_NTC_10 1
#define BAT_NTC_10 0
// >>> 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table

#define BAT_NTC_47 0

// <<< 2016/09/09-Rody, [LV3][PORTING][COMMON][BATTERY][][]RBAT_PULL_UP_R change from 63.4kohm to 91kohm
// <<< 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table
#if (LG_BL_45F1F == 1)
//#define RBAT_PULL_UP_R    63400
#define RBAT_PULL_UP_R    91000
#endif
// >>> 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table
// >>> 2016/09/09-Rody, [LV3][PORTING][COMMON][BATTERY][][]RBAT_PULL_UP_R change from 63.4kohm to 91kohm

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R    16900
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R    61900
#endif

//<2016/10/26-nickygao, [LV3][MISC][COMMON][BSP][][]Update NTC table for battery
#if (BAT_NTC_68 == 1)
#define RBAT_PULL_UP_R    91000
#endif
//<2016/10/26-nickygao

#define RBAT_PULL_UP_VOLT 1800

typedef struct _BATTERY_PROFILE_STRUCT {
	signed int percentage;
	signed int voltage;
} BATTERY_PROFILE_STRUCT, *BATTERY_PROFILE_STRUCT_P;

typedef struct _R_PROFILE_STRUCT {
	signed int resistance;
	signed int voltage;
} R_PROFILE_STRUCT, *R_PROFILE_STRUCT_P;

typedef enum {
	T1_0C,
	T2_25C,
	T3_50C
} PROFILE_TEMPERATURE;

//<2016/10/26-nickygao, [LV3][MISC][COMMON][BSP][][]Update NTC table for battery
// <<< 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table
#if 0
#if (LG_BL_45F1F == 1)
	BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20, 738977},
	{-15, 547455},
	{-10, 409599},
	{-5,  309216},
	{ 0,  235606},
	{ 5,  180980},
	{10,  140139},
	{15,  109343},
	{20,   85928},
	{25,   68000},
	{30,   54166},
	{35,   43420},
	{40,   35015},
	{45,   28405},
	{50,   23165},
	{55,   18996},
	{60,   15656},
	{65,   12966},
	{70,   10793}
};
#endif
// + 20161114-Rody, [LV3][PORTING][COMMON][BATTERY][][]NTC table add -20 to -40 table
// >>> 2016/08/09-youchihwang, [LV3][PORTING][COMMON][BATTERY][][]Porting charger, battery, NTC table
#else    /* 68k */
#if (BAT_NTC_68 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
//<2016/12/5-nickygao, [LV3][MISC][COMMON][BSP][][]Battery OTP test to get battery temperature
#if 0
{ -40 ,2735359 },
{ -39 ,2544383 },
{ -38 ,2368199 },
{ -37 ,2205554 },
{ -36 ,2055312 },
{ -35 ,1937390 },
{ -34 ,1807135 },
{ -33 ,1686614 },
{ -32 ,1575032 },
{ -31 ,1471664 },
{ -30 ,1389344 },
{ -29 ,1299322 },
{ -28 ,1215798 },
{ -27 ,1138257 },
{ -26 ,1066230 },
{ -25 ,1008014 },
{ -24 ,945021  },
{ -23 ,886422  },
{ -22 ,831881  },
{ -21 ,781089  },
#endif
//<2016/12/5-nickygao
{ -20 ,738978  }, 
{ -19 ,694417  }, 
{ -18 ,652861  }, 
{ -17 ,614088  }, 
{ -16 ,577893  }, 
{ -15 ,547456  }, 
{ -14 ,515579  }, 
{ -13 ,485782  }, 
{ -12 ,457916  }, 
{ -11 ,431842  }, 
{ -10 ,409600  }, 
{ -9  ,386554  }, 
{ -8  ,364965  }, 
{ -7  ,344730  }, 
{ -6  ,325756  }, 
{ -5  ,309217  }, 
{ -4  ,292399  }, 
{ -3  ,276610  }, 
{ -2  ,261781  }, 
{ -1  ,247847  }, 
{ 0   ,235606  }, 
{ 1   ,223208  }, 
{ 2   ,211546  }, 
{ 3   ,200570  }, 
{ 4   ,190237  }, 
{ 5   ,180980  }, 
{ 6   ,171762  }, 
{ 7   ,163075  }, 
{ 8   ,154884  }, 
{ 9   ,147158  }, 
{ 10  ,140139  }, 
{ 11  ,133227  }, 
{ 12  ,126700  }, 
{ 13  ,120536  }, 
{ 14  ,114711  }, 
{ 15  ,109344  }, 
{ 16  ,104117  }, 
{ 17  ,99174   }, 
{ 18  ,94498   }, 
{ 19  ,90071   }, 
{ 20  ,85929   }, 
{ 21  ,81948   }, 
{ 22  ,78176   }, 
{ 23  ,74602   }, 
{ 24  ,71213   }, 
{ 25  ,68000   }, 
{ 26  ,64944   }, 
{ 27  ,62045   }, 
{ 28  ,59293   }, 
{ 29  ,56680   }, 
{ 30  ,54167   }, 
{ 31  ,51805   }, 
{ 32  ,49560   }, 
{ 33  ,47426   }, 
{ 34  ,45397   }, 
{ 35  ,43421   }, 
{ 36  ,41582   }, 
{ 37  ,39833   }, 
{ 38  ,38167   }, 
{ 39  ,36582   }, 
{ 40  ,35016   }, 
{ 41  ,33576   }, 
{ 42  ,32204   }, 
{ 43  ,30896   }, 
{ 44  ,29648   }, 
{ 45  ,28406   }, 
{ 46  ,27271   }, 
{ 47  ,26188   }, 
{ 48  ,25154   }, 
{ 49  ,24168   }, 
{ 50  ,23166   }, 
{ 51  ,22266   }, 
{ 52  ,21406   }, 
{ 53  ,20585   }, 
{ 54  ,19799   }, 
{ 55  ,18997   }, 
{ 56  ,18279   }, 
{ 57  ,17593   }, 
{ 58  ,16936   }, 
{ 59  ,16308   }, 
{ 60  ,15657   }, 
{ 61  ,15082   }, 
{ 62  ,14531   }, 
{ 63  ,14003   }, 
{ 64  ,13497   }, 
{ 65  ,12967   }
};
// - 20161114-Rody, [LV3][PORTING][COMMON][BATTERY][][]NTC table add -20 to -40 table
#endif
#endif
//<2016/10/26-nickygao


#if (BAT_NTC_10 == 1)
BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20, 68237},
	{-15, 53650},
	{-10, 42506},
	{-5, 33892},
	{0, 27219},
	{5, 22021},
	{10, 17926},
	{15, 14674},
	{20, 12081},
	{25, 10000},
	{30, 8315},
	{35, 6948},
	{40, 5834},
	{45, 4917},
	{50, 4161},
	{55, 3535},
	{60, 3014}
};
#endif

#if (BAT_NTC_47 == 1)
	BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20, 483954},
	{-15, 360850},
	{-10, 271697},
	{-5, 206463},
	{0, 158214},
	{5, 122259},
	{10, 95227},
	{15, 74730},
	{20, 59065},
	{25, 47000},
	{30, 37643},
	{35, 30334},
	{40, 24591},
	{45, 20048},
	{50, 16433},
	{55, 13539},
	{60, 11210}
	};
#endif

// + 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
#if defined(CONFIG_MTK_HAFG_20)
/* T0 -10C */
BATTERY_PROFILE_STRUCT battery_profile_t0[] = {
	{0,4362},
	{3,4331},
	{5,4301},
	{8,4273},
	{10,4246},
	{13,4218},
	{15,4190},
	{18,4157},
	{20,4118},
	{23,4078},
	{25,4045},
	{28,4013},
	{30,3984},
	{33,3961},
	{35,3940},
	{38,3920},
	{41,3902},
	{43,3885},
	{46,3870},
	{48,3856},
	{51,3844},
	{53,3833},
	{56,3823},
	{58,3814},
	{61,3805},
	{63,3798},
	{66,3792},
	{68,3786},
	{71,3777},
	{74,3768},
	{76,3758},
	{79,3748},
	{81,3735},
	{84,3723},
	{86,3712},
	{89,3702},
	{91,3690},
	{94,3671},
	{96,3613},
	{98,3516},
	{99,3481},
	{99,3453},
	{100,3430},
	{100,3411},
	{100,3393},
	{100,3378},
	{100,3364},
	{100,3352},
	{100,3341},
	{100,3332},
	{100,3324},
	{100,3316},
	{100,3309},
	{100,3303},
	{100,3297},
	{100,3291},
	{100,3287},
	{100,3282},
	{100,3278},
	{100,3274},
	{100,3269},
	{100,3266},
	{100,3263},
	{100,3260},
	{100,3257},
	{100,3253},
	{100,3250},
	{100,3247},
	{100,3247}
};

/* T1 0C */
BATTERY_PROFILE_STRUCT battery_profile_t1[] = {
	{0,4383},
	{2,4353},
	{4,4317},
	{7,4256},
	{9,4219},
	{11,4192},
	{13,4166},
	{16,4143},
	{18,4119},
	{20,4097},
	{22,4080},
	{24,4056},
	{27,4028},
	{29,4003},
	{31,3982},
	{33,3965},
	{35,3948},
	{38,3930},
	{40,3908},
	{42,3887},
	{44,3870},
	{47,3855},
	{49,3842},
	{51,3831},
	{53,3821},
	{55,3812},
	{58,3804},
	{60,3797},
	{62,3791},
	{64,3787},
	{67,3784},
	{69,3780},
	{71,3777},
	{73,3772},
	{75,3766},
	{78,3757},
	{80,3747},
	{82,3735},
	{84,3722},
	{86,3707},
	{89,3696},
	{91,3686},
	{93,3678},
	{95,3656},
	{98,3580},
	{99,3487},
	{100,3448},
	{100,3419},
	{100,3394},
	{100,3374},
	{100,3354},
	{100,3337},
	{100,3321},
	{100,3308},
	{100,3294},
	{100,3283},
	{100,3272},
	{100,3263},
	{100,3252},
	{100,3244},
	{100,3235},
	{100,3227},
	{100,3219},
	{100,3212},
	{100,3206},
	{100,3200},
	{100,3195},
	{100,3188},
	{100,3188}
};

/* T2 25C */
BATTERY_PROFILE_STRUCT battery_profile_t2[] = {
	{0,4391},
	{2,4356},
	{4,4329},
	{6,4303},
	{8,4278},
	{10,4253},
	{12,4228},
	{14,4204},
	{16,4180},
	{18,4157},
	{20,4134},
	{23,4111},
	{25,4089},
	{27,4068},
	{29,4050},
	{31,4027},
	{33,4006},
	{35,3987},
	{37,3973},
	{39,3958},
	{41,3941},
	{43,3923},
	{45,3902},
	{47,3879},
	{49,3861},
	{51,3848},
	{53,3837},
	{55,3826},
	{57,3818},
	{59,3809},
	{61,3801},
	{63,3795},
	{66,3788},
	{68,3783},
	{70,3777},
	{72,3771},
	{74,3764},
	{76,3757},
	{78,3750},
	{80,3741},
	{82,3733},
	{84,3721},
	{86,3707},
	{88,3689},
	{90,3679},
	{92,3675},
	{94,3668},
	{96,3639},
	{98,3541},
	{100,3372},
	{100,3077},
	{100,3011},
	{100,2971},
	{100,2950},
	{100,2935},
	{100,2926},
	{100,2917},
	{100,2910},
	{100,2909},
	{100,2902},
	{100,2899},
	{100,2898},
	{100,2896},
	{100,2895},
	{100,2892},
	{100,2891},
	{100,2889},
	{100,2891},
	{100,2891}
};

/* T3 50C */
BATTERY_PROFILE_STRUCT battery_profile_t3[] = {
	{0,4395},
	{2,4360},
	{4,4331},
	{6,4304},
	{8,4278},
	{10,4254},
	{12,4229},
	{14,4204},
	{16,4181},
	{18,4157},
	{20,4133},
	{22,4111},
	{24,4089},
	{26,4067},
	{28,4047},
	{30,4027},
	{32,4007},
	{34,3990},
	{36,3972},
	{38,3955},
	{40,3939},
	{42,3924},
	{44,3906},
	{46,3880},
	{48,3860},
	{50,3847},
	{52,3835},
	{54,3825},
	{56,3815},
	{59,3806},
	{61,3800},
	{63,3792},
	{65,3786},
	{67,3780},
	{69,3775},
	{71,3769},
	{73,3756},
	{75,3748},
	{77,3741},
	{79,3733},
	{81,3724},
	{83,3713},
	{85,3697},
	{87,3679},
	{89,3670},
	{91,3666},
	{93,3659},
	{95,3625},
	{97,3526},
	{99,3351},
	{100,2997},
	{100,2930},
	{100,2904},
	{100,2891},
	{100,2881},
	{100,2874},
	{100,2873},
	{100,2868},
	{100,2867},
	{100,2865},
	{100,2861},
	{100,2861},
	{100,2862},
	{100,2860},
	{100,2857},
	{100,2854},
	{100,2856},
	{100,2852},
	{100,2852}
};
// - 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
#else
//<2016/10/25-nickygao, [LV3][FEATURE][COMMON][BSP][][]Set charging with -20 degree ZCV table
BATTERY_PROFILE_STRUCT battery_profile_t_n20[] = {
 {0  ,4252},
 {6  ,4221},
 {10 ,4201},
 {13 ,4163},
 {17 ,4136},
 {21 ,4108},
 {24 ,4080},
 {30 ,4047},
 {33 ,4008},
 {37 ,3968},
 {41 ,3935},
 {46 ,3903},
 {49 ,3874},
 {54 ,3851},
 {57 ,3830},
 {62 ,3810},
 {66 ,3792},
 {69 ,3775},
 {73 ,3770},
 {74 ,3766},
 {77 ,3754},
 {79 ,3743},
 {81 ,3733},
 {83 ,3724},
 {85 ,3715},
 {86 ,3708},
 {87 ,3698},
 {88 ,3688},
 {90 ,3678},
 {91 ,3668},
 {92 ,3658},
 {94 ,3652},
 {95 ,3645},
 {97 ,3640},
 {98 ,3633},
 {99 ,3627},
 {100,3623},
 {100,3400},
 {100,3400},
 {100,3400},
 {100,3381},
 {100,3353},
 {100,3330},
 {100,3311},
 {100,3293},
 {100,3278},
 {100,3264},
 {100,3252},
 {100,3241},
 {100,3232},
 {100,3224},
 {100,3216},
 {100,3209},
 {100,3203},
 {100,3197},
 {100,3191},
 {100,3187},
 {100,3182},
 {100,3178},
 {100,3174},
 {100,3169},
 {100,3166},
 {100,3163},
 {100,3160},
 {100,3157},
 {100,3153},
 {100,3150},
 {100,3147},
 {100,3147}
};
//<2016/10/25-nickygao

/* T0 -10C */
BATTERY_PROFILE_STRUCT battery_profile_t0[] = {
	{0,4362},
	{3,4331},
	{5,4301},
	{8,4273},
	{10,4246},
	{13,4218},
	{15,4190},
	{18,4157},
	{20,4118},
	{23,4078},
	{25,4045},
	{28,4013},
	{30,3984},
	{33,3961},
	{35,3940},
	{38,3920},
	{41,3902},
	{43,3885},
	{46,3870},
	{48,3856},
	{51,3844},
	{53,3833},
	{56,3823},
	{58,3814},
	{61,3805},
	{63,3798},
	{66,3792},
	{68,3786},
	{71,3777},
	{74,3768},
	{76,3758},
	{79,3748},
	{81,3735},
	{84,3723},
	{86,3712},
	{89,3702},
	{91,3690},
	{94,3671},
	{96,3613},
	{98,3516},
	{99,3481},
	{99,3453},
	{100,3430},
	{100,3411},
	{100,3393},
	{100,3378},
	{100,3364},
	{100,3352},
	{100,3341},
	{100,3332},
	{100,3324},
	{100,3316},
	{100,3309},
	{100,3303},
	{100,3297},
	{100,3291},
	{100,3287},
	{100,3282},
	{100,3278},
	{100,3274},
	{100,3269},
	{100,3266},
	{100,3263},
	{100,3260},
	{100,3257},
	{100,3253},
	{100,3250},
	{100,3247},
	{100,3247}
};

/* T1 0C */
BATTERY_PROFILE_STRUCT battery_profile_t1[] = {
	{0,4340},
	{1,4335},
	{3,4320},
	{5,4256},
	{9,4219},
	{11,4192},
	{13,4166},
	{16,4143},
	{18,4119},
	{20,4097},
	{22,4080},
	{24,4056},
	{27,4028},
	{29,4003},
	{31,3982},
	{33,3965},
	{35,3948},
	{38,3930},
	{40,3908},
	{42,3887},
	{44,3870},
	{47,3855},
	{49,3842},
	{51,3831},
	{53,3821},
	{55,3812},
	{58,3804},
	{60,3797},
	{62,3791},
	{64,3787},
	{67,3784},
	{69,3780},
	{71,3777},
	{73,3772},
	{75,3766},
	{78,3757},
	{80,3747},
	{82,3735},
	{84,3722},
	{86,3707},
	{89,3696},
	{91,3686},
	{93,3678},
	{95,3656},
	{98,3580},
	{99,3487},
	{100,3448},
	{100,3419},
	{100,3394},
	{100,3374},
	{100,3354},
	{100,3337},
	{100,3321},
	{100,3308},
	{100,3294},
	{100,3283},
	{100,3272},
	{100,3263},
	{100,3252},
	{100,3244},
	{100,3235},
	{100,3227},
	{100,3219},
	{100,3212},
	{100,3206},
	{100,3200},
	{100,3195},
	{100,3188},
	{100,3188}
};

/* T2 25C */
BATTERY_PROFILE_STRUCT battery_profile_t2[] = {
	{0,4340},
	{1,4335},
	{3,4320},
	{5,4303},
	{8,4278},
	{10,4253},
	{12,4228},
	{14,4204},
	{16,4180},
	{18,4157},
	{20,4134},
	{23,4111},
	{25,4089},
	{27,4068},
	{29,4050},
	{31,4027},
	{33,4006},
	{35,3987},
	{37,3973},
	{39,3958},
	{41,3941},
	{43,3923},
	{45,3902},
	{47,3879},
	{49,3861},
	{51,3848},
	{53,3837},
	{55,3826},
	{57,3818},
	{59,3809},
	{61,3801},
	{63,3795},
	{66,3788},
	{68,3783},
	{70,3777},
	{72,3771},
	{74,3764},
	{76,3757},
	{78,3750},
	{80,3741},
	{82,3733},
	{84,3721},
	{86,3707},
	{88,3689},
	{90,3679},
	{92,3675},
	{94,3668},
	{96,3639},
	{98,3541},
	{100,3372},
	{100,3077},
	{100,3011},
	{100,2971},
	{100,2950},
	{100,2935},
	{100,2926},
	{100,2917},
	{100,2910},
	{100,2909},
	{100,2902},
	{100,2899},
	{100,2898},
	{100,2896},
	{100,2895},
	{100,2892},
	{100,2891},
	{100,2889},
	{100,2891},
	{100,2891}
};

/* T3 50C */
BATTERY_PROFILE_STRUCT battery_profile_t3[] = {
	{0,4340},
	{1,4335},
	{3,4320},
	{5,4304},
	{8,4278},
	{10,4254},
	{12,4229},
	{14,4204},
	{16,4181},
	{18,4157},
	{20,4133},
	{22,4111},
	{24,4089},
	{26,4067},
	{28,4047},
	{30,4027},
	{32,4007},
	{34,3990},
	{36,3972},
	{38,3955},
	{40,3939},
	{42,3924},
	{44,3906},
	{46,3880},
	{48,3860},
	{50,3847},
	{52,3835},
	{54,3825},
	{56,3815},
	{59,3806},
	{61,3800},
	{63,3792},
	{65,3786},
	{67,3780},
	{69,3775},
	{71,3769},
	{73,3756},
	{75,3748},
	{77,3741},
	{79,3733},
	{81,3724},
	{83,3713},
	{85,3697},
	{87,3679},
	{89,3670},
	{91,3666},
	{93,3659},
	{95,3625},
	{97,3526},
	{99,3351},
	{100,2997},
	{100,2930},
	{100,2904},
	{100,2891},
	{100,2881},
	{100,2874},
	{100,2873},
	{100,2868},
	{100,2867},
	{100,2865},
	{100,2861},
	{100,2861},
	{100,2862},
	{100,2860},
	{100,2857},
	{100,2854},
	{100,2856},
	{100,2852},
	{100,2852}
};
#endif

// + 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
/* battery profile for actual temperature. The size should be the same as T1, T2 and T3 */
BATTERY_PROFILE_STRUCT battery_profile_temperature[] = {
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0}
};
// - 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK

#if defined(CONFIG_MTK_HAFG_20)
// + 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
/* T0 -10C */
R_PROFILE_STRUCT r_profile_t0[] = {
	{738,4362},
	{738,4331},
	{760,4301},
	{773,4273},
	{780,4246},
	{788,4218},
	{803,4190},
	{820,4157},
	{883,4118},
	{1015,4078},
	{1080,4045},
	{1093,4013},
	{1093,3984},
	{1098,3961},
	{1105,3940},
	{1110,3920},
	{1113,3902},
	{1115,3885},
	{1125,3870},
	{1138,3856},
	{1145,3844},
	{1158,3833},
	{1168,3823},
	{1178,3814},
	{1193,3805},
	{1208,3798},
	{1235,3792},
	{1263,3786},
	{1285,3777},
	{1318,3768},
	{1348,3758},
	{1383,3748},
	{1415,3735},
	{1458,3723},
	{1508,3712},
	{1568,3702},
	{1630,3690},
	{1698,3671},
	{1745,3613},
	{1793,3516},
	{1705,3481},
	{1635,3453},
	{1583,3430},
	{1528,3411},
	{1495,3393},
	{1453,3378},
	{1415,3364},
	{1388,3352},
	{1363,3341},
	{1335,3332},
	{1323,3324},
	{1303,3316},
	{1278,3309},
	{1270,3303},
	{1253,3297},
	{1245,3291},
	{1220,3287},
	{1215,3282},
	{1210,3278},
	{1213,3274},
	{1210,3269},
	{1198,3266},
	{1160,3263},
	{1178,3260},
	{1158,3257},
	{1160,3253},
	{1158,3250},
	{1175,3247},
	{1188,3247}
};
// - 20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
#else
//<2016/10/25-nickygao, [LV3][FEATURE][COMMON][BSP][][]Set charging with -20 degree ZCV table
/* T0 -20C */
R_PROFILE_STRUCT r_profile_t_n20[] = {
       {1825,4252},
	{1825,4221},
	{1845,4201},
	{1833,4163},
	{1845,4136},
	{1860,4108},
	{1893,4080},
	{1960,4047},
	{2165,4008},
	{2380,3968},
	{2373,3935},
	{2378,3903},
	{2385,3874},
	{2405,3851},
	{2418,3830},
	{2448,3810},
	{2478,3792},
	{2468,3775},
	{2458,3770},
	{2445,3766},
	{2435,3754},
	{2425,3743},
	{2418,3733},
	{2410,3724},
	{2403,3715},
	{2398,3708},
	{2395,3698},
	{2388,3688},
	{2385,3678},
	{2380,3668},
	{2373,3658},
	{2373,3652},
	{2368,3645},
	{2363,3640},
	{2360,3633},
	{2358,3627},
	{2355,3623},
	{2348,3400},
	{2348,3400},
	{2343,3400},
	{2345,3381},
	{2338,3353},
	{2340,3330},
	{2335,3311},
	{2328,3293},
	{2330,3278},
	{2325,3264},
	{2328,3252},
	{2320,3241},
	{2318,3232},
	{2315,3224},
	{2325,3216},
	{2320,3209},
	{2308,3203},
	{2315,3197},
	{2313,3191},
	{2310,3187},
	{2305,3182},
	{2310,3178},
	{2313,3174},
	{2295,3169},
	{2310,3166},
	{2305,3163},
	{2308,3160},
	{2305,3157},
	{2305,3153},
	{2308,3150},
	{2298,3147},
	{2305,3147}
};
//<2016/10/25-nickygao

/* T0 -10C */
R_PROFILE_STRUCT r_profile_t0[] = {
	{748,4362},
	{748,4331},
	{770,4301},
	{783,4273},
	{790,4246},
	{798,4218},
	{813,4190},
	{830,4157},
	{893,4118},
	{1025,4078},
	{1090,4045},
	{1103,4013},
	{1103,3984},
	{1108,3961},
	{1115,3940},
	{1120,3920},
	{1123,3902},
	{1125,3885},
	{1135,3870},
	{1148,3856},
	{1155,3844},
	{1168,3833},
	{1178,3823},
	{1188,3814},
	{1203,3805},
	{1218,3798},
	{1245,3792},
	{1273,3786},
	{1295,3777},
	{1328,3768},
	{1358,3758},
	{1393,3748},
	{1425,3735},
	{1468,3723},
	{1518,3712},
	{1578,3702},
	{1640,3690},
	{1708,3671},
	{1755,3613},
	{1803,3516},
	{1715,3481},
	{1645,3453},
	{1593,3430},
	{1538,3411},
	{1505,3393},
	{1463,3378},
	{1425,3364},
	{1398,3352},
	{1373,3341},
	{1345,3332},
	{1333,3324},
	{1313,3316},
	{1288,3309},
	{1280,3303},
	{1263,3297},
	{1255,3291},
	{1230,3287},
	{1225,3282},
	{1220,3278},
	{1223,3274},
	{1220,3269},
	{1208,3266},
	{1170,3263},
	{1188,3260},
	{1168,3257},
	{1170,3253},
	{1168,3250},
	{1185,3247},
	{1198,3247}
};
#endif

// +  20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK
/* T1 0C */
R_PROFILE_STRUCT r_profile_t1[] = {
	{390,4340},
	{390,4335},
	{398,4320},
	{443,4256},
	{530,4219},
	{540,4192},
	{543,4166},
	{550,4143},
	{555,4119},
	{563,4097},
	{588,4080},
	{603,4056},
	{600,4028},
	{595,4003},
	{593,3982},
	{600,3965},
	{605,3948},
	{608,3930},
	{595,3908},
	{590,3887},
	{590,3870},
	{595,3855},
	{598,3842},
	{608,3831},
	{615,3821},
	{620,3812},
	{633,3804},
	{643,3797},
	{658,3791},
	{675,3787},
	{700,3784},
	{725,3780},
	{753,3777},
	{785,3772},
	{818,3766},
	{855,3757},
	{895,3747},
	{948,3735},
	{1003,3722},
	{1055,3707},
	{1125,3696},
	{1208,3686},
	{1308,3678},
	{1415,3656},
	{1535,3580},
	{1730,3487},
	{1635,3448},
	{1565,3419},
	{1500,3394},
	{1450,3374},
	{1405,3354},
	{1360,3337},
	{1330,3321},
	{1283,3308},
	{1268,3294},
	{1223,3283},
	{1203,3272},
	{1180,3263},
	{1165,3252},
	{1133,3244},
	{1143,3235},
	{1118,3227},
	{1063,3219},
	{1068,3212},
	{1033,3206},
	{1018,3200},
	{1023,3195},
	{1010,3188},
	{1010,3188}
};

/* T2 25C */
R_PROFILE_STRUCT r_profile_t2[] = {
	{138,4340},
	{138,4335},
	{135,4320},
	{130,4303},
	{133,4278},
	{133,4253},
	{130,4228},
	{133,4204},
	{135,4180},
	{135,4157},
	{138,4134},
	{140,4111},
	{140,4089},
	{143,4068},
	{148,4050},
	{150,4027},
	{160,4006},
	{173,3987},
	{185,3973},
	{193,3958},
	{195,3941},
	{193,3923},
	{183,3902},
	{163,3879},
	{155,3861},
	{155,3848},
	{155,3837},
	{153,3826},
	{160,3818},
	{158,3809},
	{158,3801},
	{163,3795},
	{163,3788},
	{165,3783},
	{163,3777},
	{158,3771},
	{150,3764},
	{150,3757},
	{150,3750},
	{153,3741},
	{155,3733},
	{158,3721},
	{163,3707},
	{165,3689},
	{168,3679},
	{185,3675},
	{205,3668},
	{215,3639},
	{233,3541},
	{313,3372},
	{708,3077},
	{543,3011},
	{460,2971},
	{393,2950},
	{368,2935},
	{340,2926},
	{315,2917},
	{310,2910},
	{285,2909},
	{290,2902},
	{270,2899},
	{263,2898},
	{258,2896},
	{260,2895},
	{268,2892},
	{240,2891},
	{238,2889},
	{240,2891},
	{265,2891}
};

/* T3 50C */
R_PROFILE_STRUCT r_profile_t3[] = {
	{123,4340},
	{123,4335},
	{120,4320},
	{120,4304},
	{118,4278},
	{120,4254},
	{123,4229},
	{120,4204},
	{125,4181},
	{125,4157},
	{125,4133},
	{128,4111},
	{130,4089},
	{130,4067},
	{135,4047},
	{140,4027},
	{138,4007},
	{145,3990},
	{145,3972},
	{150,3955},
	{155,3939},
	{163,3924},
	{163,3906},
	{138,3880},
	{128,3860},
	{125,3847},
	{125,3835},
	{125,3825},
	{125,3815},
	{125,3806},
	{133,3800},
	{135,3792},
	{138,3786},
	{140,3780},
	{143,3775},
	{143,3769},
	{128,3756},
	{130,3748},
	{130,3741},
	{133,3733},
	{133,3724},
	{133,3713},
	{130,3697},
	{133,3679},
	{133,3670},
	{145,3666},
	{155,3659},
	{155,3625},
	{173,3526},
	{210,3351},
	{508,2997},
	{343,2930},
	{275,2904},
	{243,2891},
	{230,2881},
	{213,2874},
	{203,2873},
	{198,2868},
	{180,2867},
	{180,2865},
	{185,2861},
	{165,2861},
	{175,2862},
	{170,2860},
	{168,2857},
	{163,2854},
	{160,2856},
	{163,2852},
	{173,2852}
};

/* r-table profile for actual temperature. The size should be the same as T1, T2 and T3 */
R_PROFILE_STRUCT r_profile_temperature[] = {
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0}
};
// -  20161005-Rody [LV3][PORTING][COMMON][BATTERY][][] apply battery zcv table from MTK

/* ============================================================
// function prototype
// ============================================================*/
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUCT_P fgauge_get_profile(unsigned int temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUCT_P fgauge_get_profile_r_table(unsigned int temperature);

#endif	/*#ifndef _CUST_BATTERY_METER_TABLE_H*/

