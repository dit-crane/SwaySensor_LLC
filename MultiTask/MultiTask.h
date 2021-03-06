#pragma once

#include "resource.h"

#include "CTaskObj.h"
#include "CAnalyst.h"
#include "CClerk.h"
#include "CComClient.h"
#include "CComDevice.h"
#include "CPlayer.h"
#include "CPublicRelation.h"
#include "CManager.h"

///# ベース設定

//-タスク設定表示部
#define TARGET_RESOLUTION			1		//マルチメディアタイマーイベント分解能
#define SYSTEM_TICK_ms				25		//メインスレッド周期
#define MAX_APL_TASK				8		//スレッド最大数
#define INITIAL_TASK_STACK_SIZE		16384	//各スレッド用スタックサイズ

//-Main Windowの初期サイズ、位置設定
//#define MAIN_WND_INIT_SIZE_W		620
//#define MAIN_WND_INIT_SIZE_H		420
#define MAIN_WND_INIT_POS_X			20
#define MAIN_WND_INIT_POS_Y			20

//-Tweet Message表示用Static Windowのサイズ設定値
#define MSG_WND_H					20	//Height of window
#define MSG_WND_W					590	//Width of window
#define MSG_WND_ORG_X				35	//Origin X of window arrangement 
#define MSG_WND_ORG_Y				10	//Origin Y of window arrangement 
#define MSG_WND_Y_SPACE				12	//Space between windows Y direction 
#define TWEET_IMG_ORG_X				5	//Origin X of bitmap icon arrangement

//-各タスクアイコン用イメージリスト設定値
#define ICON_IMG_W					32	//イメージ幅
#define ICON_IMG_H					32	//イメージ高さ

//-各タスク設定用タブ関連
#define TAB_DIALOG_W				620
#define TAB_DIALOG_H				300
#define TAB_POS_X					10
#define TAB_POS_Y					MSG_WND_ORG_Y+(MSG_WND_H+MSG_WND_Y_SPACE)*TASK_NUM+10
#define TAB_SIZE_H					35

//-ID定義 Mainスレッド用　WM_USER + 1000 + α
#define ID_STATUS					WM_USER + 1001
#define ID_STATIC_MAIN				WM_USER + 1002
#define ID_TASK_SET_TAB				WM_USER + 1003


//-.ini 関連設定


//#define PATH_OF_INIFILE					L"./app.ini"	//オプショナルパス

#define NAME_OF_INIFILE					L"app" //iniファイルファイル名
#define EXT_OF_INIFILE					L"ini" //iniファイル拡張子
#define PATH_OF_INIFILE					pszInifile //オプショナルパス
#define PATH_OF_EXEFILE					wstrPathExe //EXEのPATH

#define OPATH_SECT_OF_INIFILE			L"PATH"			//オプショナルパスセクション
#define OBJ_NAME_SECT_OF_INIFILE		L"OBJECT_NAME"	//オブジェクトフルネームセクション
#define OBJ_SNAME_SECT_OF_INIFILE		L"OBJECT_SNAME"	//オブジェクト略称セクション
#define COMM_SECT_OF_INIFILE			L"COM_PARAM"	//Communicatorタスクセクション
#define SMEM_SECT_OF_INIFILE			L"SMEM"			//共有メモリセクション

//共有メモリ
//共有メモリ定義数
#define SMEM_MAX						8
//情報を参照するためのキー
#define SMEM_COM_TABLE_ID				0
#define SMEM_MODE_ID					1
#define SMEM_FAULT_ID					2
#define SMEM_IOTBL_ID					3
#define SMEM_NAME0_KEY_OF_INIFILE		L"NAME0"
#define SMEM_NAME1_KEY_OF_INIFILE		L"NAME1"
#define SMEM_NAME2_KEY_OF_INIFILE		L"NAME2"
#define SMEM_NAME3_KEY_OF_INIFILE		L"NAME3"
#define SMEM_NAME4_KEY_OF_INIFILE		L"NAME4"
#define SMEM_NAME5_KEY_OF_INIFILE		L"NAME5"
#define SMEM_NAME6_KEY_OF_INIFILE		L"NAME6"
#define SMEM_NAME7_KEY_OF_INIFILE		L"NAME7"
#define SMEM_NAME8_KEY_OF_INIFILE		L"NAME8"
#define SMEM_NAME9_KEY_OF_INIFILE		L"NAME9"

//各セクションの各タスク用の情報を参照するためのキー
#define MAIN_KEY_OF_INIFILE				L"MAIN"
#define CLIENT_COM_KEY_OF_INIFILE		L"CCOM"
#define CLERK_KEY_OF_INIFILE			L"CLERK"
#define DEVICE_COM_KEY_OF_INIFILE		L"DCOM"
#define ANALYST_KEY_OF_INIFILE			L"ANALYST"
#define PLAYER_KEY_OF_INIFILE			L"PLAYER"
#define MANAGER_KEY_OF_INIFILE			L"MANAGER"
#define PR_KEY_OF_INIFILE				L"PR"
#define DEFAULT_KEY_OF_INIFILE			L"DEFAULT"
#define HELPER_KEY_OF_INIFILE			L"HELPER"
#define DUMMY_KEY_OF_INIFILE			L"DUMMY"

///# マルチスレッド管理用構造体
typedef struct knl_manage_set_tag {
	WORD mmt_resolution = TARGET_RESOLUTION;	//マルチメディアタイマーの分解能
	unsigned int cycle_base = SYSTEM_TICK_ms;
	WORD KnlTick_TimerID;						//マルチメディアタイマーのID
	unsigned int num_of_task = 0;		//アプリケーションで利用するスレッド数
	unsigned long sys_counter = 0;
	SYSTEMTIME Knl_Time;				//アプリケーション開始からの経過時間
	unsigned int stackSize = INITIAL_TASK_STACK_SIZE;	//タスクの初期スタックサイズ
}ST_KNL_MANAGE_SET, *P_ST_MANAGE_SET;



#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))
#endif

