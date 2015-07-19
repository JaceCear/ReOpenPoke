//------------------------------------------------------------//
//             mks4agbLib.h ( m4aLib.h ) ver1.05              //
//                                                            //
//          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.         //
//------------------------------------------------------------//

#ifndef _M4A_LIB_H
#define _M4A_LIB_H

#define _M4A_LIB_VER 105

#include "AgbSound.h"


//Structure of CGB Virtual Channel
typedef struct {
    u8 ch1[64];
    u8 ch2[64];
    u8 ch3[64];
    u8 ch4[64];
} CgbChannels;

//Structure of Music Player Table
typedef struct {
    MusicPlayerArea *ma;
    MusicPlayerTrack *ta;
    u32 tn;
} MPlayTable;

//Structure of Song Table
typedef struct {
    SongHeader *so;
    u16 ms, me;
} SongTable;


#define CGB1_P12 ((WaveData *)0)
#define CGB1_P25 ((WaveData *)1)
#define CGB1_P50 ((WaveData *)2)
#define CGB1_P75 ((WaveData *)3)
#define CGB2_P12 CGB1_P12
#define CGB2_P25 CGB1_P25
#define CGB2_P50 CGB1_P50
#define CGB2_P75 CGB1_P75
#define CGB4_C15 ((WaveData *)0)
#define CGB4_C07 ((WaveData *)1)


extern const u8 __sound_mode_i[];
#define sound_mode_i ((u32)__sound_mode_i)
extern const u8 __total_mplay_n[];
#define total_mplay_n ((u16)__total_mplay_n)
extern const u8 __total_song_n[];
#define total_song_n ((u16)__total_song_n)

extern SoundArea m4a_sound;
extern const MPlayTable mplay_table[];
extern const SongTable song_table[];
extern u8 m4a_memacc_area[];


extern void m4aSoundInit(void);

#define m4aSoundMode(P1) SoundMode_rev01(P1)
extern void SoundMode_rev01(u32 mode);

extern void m4aSoundMain(void);

#define m4aSoundVSync() SoundVSync_rev01()
extern void SoundVSync_rev01(void);

#define m4aSoundVSyncOff() SoundVSyncOff_rev01()
extern void SoundVSyncOff_rev01(void);

#define m4aSoundVSyncOn() SoundVSyncOn_rev01()
extern void SoundVSyncOn_rev01(void);

#define m4aMPlayStart(P1,P2) MPlayStart_rev01(P1,P2)
extern void MPlayStart_rev01(MusicPlayerArea *ma, SongHeader *so);

extern void m4aSongNumStart(u16 n);

extern void m4aSongNumStartOrChange(u16 n);

extern void m4aSongNumStartOrContinue(u16 n);

extern void m4aMPlayImmInit(MusicPlayerArea *ma);

#define m4aMPlayStop(P1) MPlayStop_rev01(P1)
extern void MPlayStop_rev01(MusicPlayerArea *ma);

extern void m4aSongNumStop(u16 n);

extern void m4aMPlayAllStop(void);

extern void m4aMPlayContinue(MusicPlayerArea *ma);

extern void m4aSongNumContinue(u16 n);

extern void m4aMPlayAllContinue(void);

extern void m4aMPlayFadeOut(MusicPlayerArea *ma, u16 sp);

#define m4aMPlayTempoControl(P1,P2) MPlayTempoControl(P1,P2)
extern void MPlayTempoControl(MusicPlayerArea *ma, u16 te);

#define m4aMPlayVolumeControl(P1,P2,P3) MPlayVolumeControl(P1,P2,P3)
extern void MPlayVolumeControl(MusicPlayerArea *ma, u16 tb, u16 vo);

#define m4aMPlayPitchControl(P1,P2,P3) MPlayPitchControl(P1,P2,P3)
extern void MPlayPitchControl(MusicPlayerArea *ma, u16 tb, s16 pi);

#define m4aMPlayPampotControl(P1,P2,P3) MPlayPanpotControl(P1,P2,P3)
#define m4aMPlayPanpotControl(P1,P2,P3) MPlayPanpotControl(P1,P2,P3)
extern void MPlayPanpotControl(MusicPlayerArea *ma, u16 tb, s8 pa);

#define m4aMPlayModDepthSet(P1,P2,P3) MPlayModDepthSet(P1,P2,P3)
extern void MPlayModDepthSet(MusicPlayerArea *ma, u16 tb, u8 md);

#define m4aMPlayLFOSpeedSet(P1,P2,P3) MPlayLFOSpeedSet(P1,P2,P3)
extern void MPlayLFOSpeedSet(MusicPlayerArea *ma, u16 tb, u8 ls);


#endif // _M4A_LIB_H

// MusicPlayers
extern MusicPlayerArea m4a_mplay000;
extern MusicPlayerArea m4a_mplay001;
extern MusicPlayerArea m4a_mplay002;
extern MusicPlayerArea m4a_mplay003;

// Song files
	
extern SongHeader levelup;
extern SongHeader evo;
extern SongHeader battle1;
extern SongHeader battle2;
extern SongHeader battle3;
extern SongHeader battle4;
extern SongHeader battle5;
extern SongHeader battle6;
extern SongHeader victory1;
extern SongHeader victory2;
extern SongHeader victory3;
extern SongHeader victory2_bis;
extern SongHeader fanfare1;
extern SongHeader fanfare2;
extern SongHeader fanfare3;
extern SongHeader fanfare4;
extern SongHeader fanfare5;
extern SongHeader encount1;
extern SongHeader encount2;
extern SongHeader encount3;
extern SongHeader encount4;
extern SongHeader youfail;
extern SongHeader youfail2;
extern SongHeader follow;
extern SongHeader gamecorner;
extern SongHeader evillurks;
extern SongHeader gym;
extern SongHeader jigglypuff;
extern SongHeader gamefreak;
extern SongHeader intro;
extern SongHeader title;
extern SongHeader cinnabar;
extern SongHeader lavender;
extern SongHeader forest;
extern SongHeader mountmoon;
extern SongHeader abandon;
extern SongHeader route1;
extern SongHeader route2;
extern SongHeader route3;
extern SongHeader route4;
extern SongHeader indigo;
extern SongHeader pallet;
extern SongHeader oaklab;
extern SongHeader oaktheme;
extern SongHeader center;
extern SongHeader ssanne;
extern SongHeader tower;
extern SongHeader silph;
extern SongHeader cerulean;
extern SongHeader celadon;
extern SongHeader vermillion;
extern SongHeader viridian;
extern SongHeader islands45;
extern SongHeader islands67;
extern SongHeader waterlabyrinth;
extern SongHeader gary;
extern SongHeader gary_bis;
extern SongHeader intromsg1;
extern SongHeader intromsg2;
extern SongHeader intromsg3;
extern SongHeader bike;
extern SongHeader cardphoto;
extern SongHeader deoxys;
extern SongHeader deoxys_enc;
extern SongHeader ending;
extern SongHeader halloffame;
extern SongHeader trading;
extern SongHeader mysteryconnect;
extern SongHeader pallet_fame;
extern SongHeader surfing;
extern SongHeader teachytv;
extern SongHeader healing;
extern SongHeader thexder;
extern SongHeader gyakuten;
extern SongHeader gast_enc;
extern SongHeader rmxp06;
extern SongHeader toho;
extern SongHeader zelda;
extern SongHeader Still_Alive;
extern SongHeader nsmbfinalbattle;
extern SongHeader rockmike;
extern SongHeader duelfates;
extern SongHeader dw2;
extern SongHeader cavestory;
extern SongHeader th09_02;
extern SongHeader VsDialgaPalkia;

extern SongHeader sfx001;
extern SongHeader sfx002;
extern SongHeader sfx003;
extern SongHeader sfx004;
extern SongHeader sfx005;
extern SongHeader sfx006;
extern SongHeader sfx007;
extern SongHeader sfx008;
extern SongHeader sfx009;
extern SongHeader sfx010;
extern SongHeader sfx011;
extern SongHeader sfx012;
extern SongHeader sfx013;
extern SongHeader sfx014;
extern SongHeader sfx015;
extern SongHeader sfx016;
extern SongHeader sfx017;
extern SongHeader sfx018;
extern SongHeader sfx019;
extern SongHeader sfx020;
extern SongHeader sfx021;
extern SongHeader sfx022;
extern SongHeader sfx023;
extern SongHeader sfx024;
extern SongHeader sfx025;
extern SongHeader sfx026;
extern SongHeader sfx027;
extern SongHeader sfx028;
extern SongHeader sfx029;
extern SongHeader sfx030;
extern SongHeader sfx031;
extern SongHeader sfx032;
extern SongHeader sfx033;
extern SongHeader sfx034;
extern SongHeader sfx035;
extern SongHeader sfx036;
extern SongHeader sfx037;
extern SongHeader sfx038;
extern SongHeader sfx039;
extern SongHeader sfx040;
extern SongHeader sfx041;
extern SongHeader sfx042;
extern SongHeader sfx043;
extern SongHeader sfx044;
extern SongHeader sfx045;
extern SongHeader sfx046;
extern SongHeader sfx047;
extern SongHeader sfx048;
extern SongHeader sfx049;
extern SongHeader sfx050;
extern SongHeader sfx051;
extern SongHeader sfx052;
extern SongHeader sfx053;
extern SongHeader sfx054;
extern SongHeader sfx055;
extern SongHeader sfx056;
extern SongHeader sfx057;
extern SongHeader sfx058;
extern SongHeader sfx059;
extern SongHeader sfx060;
extern SongHeader sfx061;
extern SongHeader sfx062;
extern SongHeader sfx063;
extern SongHeader sfx064;
extern SongHeader sfx065;
extern SongHeader sfx066;
extern SongHeader sfx067;
extern SongHeader sfx068;
extern SongHeader sfx069;
extern SongHeader sfx070;
extern SongHeader sfx071;
extern SongHeader sfx072;
extern SongHeader sfx073;
extern SongHeader sfx074;
extern SongHeader sfx075;
extern SongHeader sfx076;
extern SongHeader sfx077;
extern SongHeader sfx078;
extern SongHeader sfx079;
extern SongHeader sfx080;
extern SongHeader sfx081;
extern SongHeader sfx082;
extern SongHeader sfx083;
extern SongHeader sfx084;
extern SongHeader sfx085;
extern SongHeader sfx086;
extern SongHeader sfx087;
extern SongHeader sfx088;
extern SongHeader sfx089;
extern SongHeader sfx090;
extern SongHeader sfx091;
extern SongHeader sfx092;
extern SongHeader sfx093;
extern SongHeader sfx094;
extern SongHeader sfx095;
extern SongHeader sfx096;
extern SongHeader sfx097;
extern SongHeader sfx098;
extern SongHeader sfx099;
extern SongHeader sfx100;
extern SongHeader sfx101;
extern SongHeader sfx102;
extern SongHeader sfx103;
extern SongHeader sfx104;
extern SongHeader sfx105;
extern SongHeader sfx106;
extern SongHeader sfx107;
extern SongHeader sfx108;
extern SongHeader sfx109;
extern SongHeader sfx110;
extern SongHeader sfx111;
extern SongHeader sfx112;
extern SongHeader sfx113;
extern SongHeader sfx114;
extern SongHeader sfx115;
extern SongHeader sfx116;
extern SongHeader sfx117;
extern SongHeader sfx118;
extern SongHeader sfx119;
extern SongHeader sfx120;
extern SongHeader sfx121;
extern SongHeader sfx122;
extern SongHeader sfx123;
extern SongHeader sfx124;
extern SongHeader sfx125;
extern SongHeader sfx126;
extern SongHeader sfx127;
extern SongHeader sfx128;
extern SongHeader sfx129;
extern SongHeader sfx130;
extern SongHeader sfx131;
extern SongHeader sfx132;
extern SongHeader sfx133;
extern SongHeader sfx134;
extern SongHeader sfx135;
extern SongHeader sfx136;
extern SongHeader sfx137;
extern SongHeader sfx138;
extern SongHeader sfx139;
extern SongHeader sfx140;
extern SongHeader sfx141;
extern SongHeader sfx142;
extern SongHeader sfx143;
extern SongHeader sfx144;
extern SongHeader sfx145;
extern SongHeader sfx146;
extern SongHeader sfx147;
extern SongHeader sfx148;
extern SongHeader sfx149;
extern SongHeader sfx150;
extern SongHeader sfx151;
extern SongHeader sfx152;
extern SongHeader sfx153;
extern SongHeader sfx154;
extern SongHeader sfx155;
extern SongHeader sfx156;
extern SongHeader sfx157;
extern SongHeader sfx158;
extern SongHeader sfx159;
extern SongHeader sfx160;
extern SongHeader sfx161;
extern SongHeader sfx162;
extern SongHeader sfx163;
extern SongHeader sfx164;
extern SongHeader sfx165;
extern SongHeader sfx166;
extern SongHeader sfx167;
extern SongHeader sfx168;
extern SongHeader sfx169;
extern SongHeader sfx170;
extern SongHeader sfx171;
extern SongHeader sfx172;
extern SongHeader sfx173;
extern SongHeader sfx174;
extern SongHeader sfx175;
extern SongHeader sfx176;
extern SongHeader sfx177;
extern SongHeader sfx178;
extern SongHeader sfx179;
extern SongHeader sfx180;
extern SongHeader sfx181;
extern SongHeader sfx182;
extern SongHeader sfx183;
extern SongHeader sfx184;
extern SongHeader sfx185;
extern SongHeader sfx186;
extern SongHeader sfx187;
extern SongHeader sfx188;
extern SongHeader sfx189;
extern SongHeader sfx190;
extern SongHeader sfx191;
extern SongHeader sfx192;
extern SongHeader sfx193;
extern SongHeader sfx194;
extern SongHeader sfx195;
extern SongHeader sfx196;
extern SongHeader sfx197;
extern SongHeader sfx198;
extern SongHeader sfx199;
extern SongHeader sfx200;
extern SongHeader sfx201;
extern SongHeader sfx202;
extern SongHeader sfx203;
extern SongHeader sfx204;
extern SongHeader sfx205;
extern SongHeader sfx206;
extern SongHeader sfx207;
extern SongHeader sfx208;
extern SongHeader sfx209;
extern SongHeader sfx210;
extern SongHeader sfx211;
extern SongHeader sfx212;
extern SongHeader sfx213;
extern SongHeader sfx214;
extern SongHeader sfx215;
extern SongHeader sfx216;
extern SongHeader sfx217;
extern SongHeader sfx218;
extern SongHeader sfx219;
extern SongHeader sfx220;
extern SongHeader sfx221;
extern SongHeader sfx222;
extern SongHeader sfx223;
extern SongHeader sfx224;
extern SongHeader sfx225;
extern SongHeader sfx226;
extern SongHeader sfx227;
extern SongHeader sfx228;
extern SongHeader sfx229;
extern SongHeader sfx230;
extern SongHeader sfx231;
extern SongHeader sfx232;
extern SongHeader sfx233;
extern SongHeader sfx234;
extern SongHeader sfx235;
extern SongHeader sfx236;
extern SongHeader sfx237;
extern SongHeader sfx238;
extern SongHeader sfx239;
extern SongHeader sfx240;
extern SongHeader sfx241;
extern SongHeader sfx242;
extern SongHeader sfx243;
extern SongHeader sfx244;
extern SongHeader sfx245;
extern SongHeader sfx246;
extern SongHeader sfx247;
extern SongHeader sfx248;
extern SongHeader sfx249;
extern SongHeader sfx250;
extern SongHeader sfx251;
extern SongHeader sfx252;
extern SongHeader sfx253;
extern SongHeader sfx254;
extern SongHeader sfx255;
extern SongHeader sfx256;
