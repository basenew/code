#ifndef __COMM_LOG_H__
#define __COMM_LOG_H__

#include "typedef.h"
#include "sys.h"
#include <fstream>
#include <mutex>
#include <thread>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

namespace comm
{

	using pcchar = const char*;

	class Log:public ofstream
	{
		public:
			enum ENLVL{
				LVL_NON,
				LVL_SYS,
				LVL_ERR,
				LVL_MSG,
				LVL_DBG,
				LVL_ALL,
			};

			enum ENOUT{
				OUT_STT = 0,
				OUT_FLE = 1,
				OUT_STD = 2,
				OUT_SYS = 4,
				OUT_NET = 8,

			};

			enum ENSPT{
				SPT_HOUR,
				SPT_MINU,
				SPT_LINE,
				SPT_SIZE,
			};

			bool if_log(ENLVL lvl){return lvl <= _lvl;}

		private:
			bool _safe;	
			long _size;
			long _line;

			string _path;
			string _name;

			int    _eout;
			ENLVL  _lvl;
			ENSPT  _split;

			ofstream _out;

		private:
			Log():
			_safe(false),
			_size(0),
			_line(0),
			_eout(OUT_STT|OUT_FLE),
			_lvl(LVL_DBG),
			_split(SPT_HOUR){
				gen_file_name();
				open(_path+_name, ios::out|ios::trunc);
				//open("log", ios::out|ios::trunc);
				if (!is_open()) cout << "open " << _path << _name << " err:" << get_errno_str() << endl;
			}

			~Log(){
				_out.close();
			}

			void gen_file_name(){
				if (_name.empty()){
					string date_time = get_time_string("_");	
					stringstream ss;
					ss << date_time << "_" << getpid() << ".log";
					ss >> _name;
					cout << "new name:" << _name << endl;
//					_name = "test.log";
				}
			}

		public:
			static Log& ins(){
				static Log log;
				return log;
			}
	};

}
#define LOGIF(L) if (Log::ins().if_log(L))Log::ins()<<get_time_string()<<" "<<__FILE__<<":"<<__LINE__ <<" "<<__FUNCTION__<<" "<< pthread_self()<< " "
#define LDBG LOGIF(Log::LVL_DBG)
#define LMSG LOGIF(Log::LVL_MSG)
#define LERR LOGIF(Log::LVL_ERR)
#define LSYS LOGIF(Log::LVL_SYS)

#define LOG_DBG LOGIF(Log::LVL_DBG)
#define LOG_MSG LOGIF(Log::LVL_MSG)
#define LOG_ERR LOGIF(Log::LVL_ERR)
#define LOG_SYS LOGIF(Log::LVL_SYS)
#endif
