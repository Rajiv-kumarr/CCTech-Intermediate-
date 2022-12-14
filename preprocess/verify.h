#pragma once

#ifndef verify
#define verify(cond) \
do\
{\
if(!(cond))\
    {cerr<<__FILE__<<":"<< __LINE__<<": "<<"error: In function "<<__func__<< "(), "<<"verification of condition '" <<#cond<<"' failed."<<endl;\
    }\
}while(0)
 
#endif


