#pragma once

namespace dvc{
enum ErrCode{
    ERR_BASE = 0,
    ERR_OK   = ERR_BASE,
    ERR_FAIL = 1,
    ERR_NET_BASE = 100,

    ERR_PROTO_BASE = 200,

    ERR_DB_BASE    = 300,

    ERR_APP_BASE   = 500
};
}
