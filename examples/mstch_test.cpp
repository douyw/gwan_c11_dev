// ============================================================================
// C++ servlet example for the G-WAN Web Application Server   (http://gwan.ch/)
// ----------------------------------------------------------------------------
// hello.cpp: hello world C++ example
//
// This code was submitted and written by Thomas Meitz (gwan at jproxx dot com)
// ============================================================================
// imported functions:
//   get_reply(): get a pointer on the 'reply' dynamic buffer from the server
//   xbuf_cat(): like strcat(), but it works in the specified dynamic buffer
// ----------------------------------------------------------------------------
#pragma link mstch

#include "gwan.h" // G-WAN definitions
#include <string>
#include <iostream>
#include <mstch/mstch.hpp>

using namespace std;

std::string test_mstch() {
  std::string view{"{{#names}}Hi {{name}}!\n{{/names}}"};
  mstch::map context{
    {"names", mstch::array{
      mstch::map{{"name", std::string{"Chris"}}},
      mstch::map{{"name", std::string{"Mark"}}},
      mstch::map{{"name", std::string{"Scott"}}},
    }}
  };

  return mstch::render(view, context);
}

class Hello
{
public:
   void whatsup(xbuf_t* reply, string& str)
   {
      xbuf_cat(reply, (char*)str.c_str());
   }
};

// ----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
   string h = test_mstch();
   Hello hello;
   hello.whatsup(get_reply(argv), h);

   return 200; // return an HTTP code (200:'OK')
}
// ============================================================================
// End of Source Code
// ============================================================================
