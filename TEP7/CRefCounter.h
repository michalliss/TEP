//
// Created by przydasie on 11/30/19.
//

#ifndef TEP7__CREFCOUNTER_H_
#define TEP7__CREFCOUNTER_H_

class CRefCounter {
   public:
    CRefCounter() { i_count; }
    int iAdd() { return(++i_count); }
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
   private:
    int i_count;
};

#endif //TEP7__CREFCOUNTER_H_
