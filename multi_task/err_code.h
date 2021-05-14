#pragma once
namespace stg{
enum error_code{
ERR_OK = 0,
ERR_FAIL = 1,

ERR_THD_BASE = 1,
ERR_TSK_BASE = 100,
ERR_MSG_BASE = 200,

ERR_APP_BASE = 500
}; 

const string& err_msg(error_code err);
}

