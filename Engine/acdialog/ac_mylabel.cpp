
#include <string.h>
#include "wgt2allg.h"
#include "ali3d.h"
#include "acdialog/ac_mylabel.h"
#include "acdialog/ac_cscidialog.h"
#include "acdialog/ac_dialoginternaldefines.h"

MyLabel::MyLabel(int xx, int yy, int wii, char *tee)
{
    strncpy(text, tee, 150);
    text[149] = 0;
    x = xx;
    y = yy;
    wid = wii;
    hit = TEXT_HT;
}

void MyLabel::draw()
{
    int curofs = 0, lastspac = 0, cyp = y;
    char *teptr = &text[0];
    wtextcolor(0);

    break_up_text_into_lines(wid, acdialog_font, teptr);
    for (int ee = 0; ee < numlines; ee++) {
        wouttext_outline(x, cyp, acdialog_font, lines[ee]);
        cyp += TEXT_HT;
    }
    /*
    while (1) {
    if ((teptr[curofs] == ' ') | (teptr[curofs] == 0)) {
    int itwas = teptr[curofs];
    teptr[curofs] = 0;
    if (wgettextwidth(teptr, cbuttfont) > wid) {
    teptr[curofs] = itwas;
    teptr[lastspac] = 0;
    wouttextxy(x, cyp, cbuttfont, teptr);
    teptr[lastspac] = ' ';
    teptr += lastspac + 1;
    curofs = 0;
    cyp += TEXT_HT;
    } else
    teptr[curofs] = itwas;

    lastspac = curofs;
    }

    if (teptr[curofs] == 0)
    break;

    curofs++;
    }
    wouttextxy(x, cyp, cbuttfont, teptr);*/
}

int MyLabel::pressedon()
{
    return 0;
}

int MyLabel::processmessage(int mcode, int wParam, long lParam)
{
    return -1;                  // doesn't support messages
}