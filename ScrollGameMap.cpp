#include "ScrollGame.h"

char map[height][width] =
{
	"                   s        s cccc       s                                  s    cccccc         s       s       ccc           s                        cccc      s         s                         s  ",
	"     s                        cccc                cccc  s        s               cccccc     s      s            ccc                  cccccc   s        cccc                   cccc    s       s         ",
	"            ccccc          s     s            s   cccc                   s           s                  s           s      s         cccccc           s          s            cccc                      ",
	"            ccccc                  ccc            cccc                          s                  cccc                           s                      ccccc                                 cccccc   ",
	"  s                 s              ccc s                          s    cccc             s          cccc      s        ccc                s               ccccc        s                   s    cccccc   ",
	"        s                   s                    s             s       cccc    s               s     s                ccc     s                  s              s                s      n        s      ",
	"                                                      f                                                               ccc                                 b                             l               ",
	"                                                     f f                                                                                                                            f   l               ",
	"                                                                                        f                                             w                                             d   l               ",
	"                           ddd   ddd                                                                                                 w w               b                         f      l   d d d       ",
	"                                                    y   y                        f                                                  w   w                                        d      l   ddddd       ",
	"                                                   yy   yy         f                      qq                                       wxxxxxw                                    f         l   ddddd       ",
	"       m                ddd   ddd   drd m         yyy   yyy       f f      m        qq    qq                              fffff     xxxxx           b                         d   m     l   ddddd       ",
	"      mmm                              mmm       yyyy   yyyy              mmmqq     qq    qq                              fffff     xxjxx                                        mmm    l   dd dd       ",
	"     mmmmm     ggg  ggg               mmmmm     yyyyy   yyyyy     ggg    mmmmqq     qq    qq                          ggg fffff gg  xxjxx g                                     mmmmm   d   dd dd       ",
	"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy   yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy   y   y   y   yyyyyyyyyyyyyyyyyyyyyyy     b                   yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   b   b   b   bbbbbbbbbbbbbbbbbbbbbbb                         bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   b   b   b   bbbbbbbbbbbbbbbbbbbbbbb                         bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   b   b   b   bbbbbbbbbbbbbbbbbbbbbbb  b                      bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   b   b   b   bbbbbbbbbbbbbbbbbbbbbbb                         bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
};