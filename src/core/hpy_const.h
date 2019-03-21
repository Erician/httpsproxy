#ifndef HPY_CORE_HPY_CONST_
#define HPY_CORE_HPY_CONST_

namespace hpy
{
    namespace Proxy
    {
        const short kHttpsDefaultPort = 443;
        const short kHttpsDefaultProxyPort = 1081;
        const short kHttpDefaultPort = 80;
        const short kHttpDefaultProxyPort = 8081;
        const int kMaxConnections = 50;   
        const int kListenQ = 10;
    };//proxy

    namespace Tcp
    {
        const int kMss = 1460;
        const int kMaxDataLength = 65535;
    };//Tcp



};//hpy
#endif
