
#include "LectorINT.hpp"

/**
 * @brief 
 * 
 * @param theStringVector
 * @param theString
 * @param theDelimiter
 */
void LectorINT::split(vector<string> &theStringVector, const string &theString, const string &theDelimiter) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = theString.find(theDelimiter, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        theStringVector.push_back(theString.substr(start,
                                                   (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = ((end > (string::npos - theDelimiter.size()))
                 ? string::npos : end + theDelimiter.size());
    }
}


/**
 *
 */
void LectorINT::inicia() {
    string sline;

    ifstream miarch;

    miarch.open(sarchivo.c_str(), ifstream::in);

    while (getline(miarch, sline)) {
        parser(sline);
    }

    miarch.close();
}


/**
 *
 * @param scad
 */
void LectorINT::parser(string scad) {

    vector<string> vc;

    split(vc, scad, sep);

}

/**
 * 
 */
void LectorINT::creaPoligono(string scad, vector<Punto>& vpuntos) {
    vector<string> vc;

    split(vc, scad, ",");

    for(auto iter = vc.begin();iter<vc.end(); iter +=2){
        Punto p;
        //(atof(iter->c_str()),atof((iter+1)->c_str()));
        vpuntos.push_back(p);
    }
}



