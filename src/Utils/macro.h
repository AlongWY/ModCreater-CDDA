#ifndef MODCREATER_CDDA_MACRO_H
#define MODCREATER_CDDA_MACRO_H

#define D_GET_CHECK(JSON, OBJ, ATTR)     if ((JSON).find(#ATTR) != (JSON).end()) (OBJ).ATTR = (JSON)[#ATTR];
#define D_GET_CHECK_DIF(JSON, OBJ, ATTR, NAME)     if ((JSON).find(#NAME) != (JSON).end()) (OBJ).ATTR = (JSON)[#NAME];
#define J_GET_CHECK(JSON, OBJ, ATTR)         (JSON)[#ATTR] = (OBJ).ATTR;
#define J_GET_CHECK_DIF(JSON, OBJ, ATTR, NAME)     (JSON)[#NAME] = (OBJ).ATTR;
#define J_GET_OPTIONAL(JSON, OBJ, ATTR, DEFAULT)        if(((OBJ).ATTR)!=(DEFAULT)){(JSON)[#ATTR] = (OBJ).ATTR;}
#define J_GET_OPTIONAL_DIF(JSON, OBJ, ATTR, NAME, DEFAULT)    if(((OBJ).ATTR)!=(DEFAULT)){ (JSON)[#NAME] = (OBJ).ATTR;}

#define J_GET_STRING(JSON, OBJ, ATTR) if(!(((OBJ).ATTR).empty())){(JSON)[#ATTR] = (OBJ).ATTR;}
#define J_GET_STRING_DIF(JSON, OBJ, ATTR, NAME) if(!(((OBJ).ATTR).empty())){ (JSON)[#NAME] = (OBJ).ATTR;}

#define D_GET_VEC_CHECK(JSON, OBJ, ATTR)     if ((JSON).find(#ATTR) != (JSON).end())\
                                                for (const auto &element : (JSON)[#ATTR])(OBJ).ATTR.push_back(element);
#define D_GET_VEC_CHECK_DIF(JSON, OBJ, ATTR, NAME)     if ((JSON).find(#NAME) != (JSON).end())\
                                                        for (const auto &element : (JSON)[#ATTR])(OBJ).ATTR.push_back(element);
#define J_GET_VEC(JSON, OBJ, ATTR)   if(!((OBJ).ATTR).empty()){(JSON)[#ATTR] = (OBJ).ATTR;}
#define J_GET_VEC_DIF(JSON, OBJ, ATTR, NAME) if(!((OBJ).ATTR).empty()) {(JSON)[#NAME] = (OBJ).ATTR;}

#define D_GET_MAP_CHECK(JSON, OBJ, ATTR)  if ((JSON).find(#ATTR) != (JSON).end())\
                                                    for (const auto &element : (JSON)[#ATTR])\
                                                        (OBJ).ATTR.emplace(element[0], element[1]);
#define D_GET_MAP_CHECK_DIF(JSON, OBJ, ATTR, NAME)  if ((JSON).find(#NAME) != (JSON).end())\
                                                    for (const auto &element : (JSON)[#NAME])\
                                                        (OBJ).ATTR.emplace(element[0], element[1]);
#define J_GET_MAP(JSON, OBJ, ATTR)     if(!((OBJ).ATTR).empty()) { for (auto &element:(OBJ).ATTR)(JSON)[#ATTR].push_back({element.first, element.second});}
#define J_GET_MAP_DIF(JSON, OBJ, ATTR, NAME)    if(!((OBJ).ATTR).empty()){ for (auto &element:(OBJ).ATTR)(JSON)[#NAME].push_back({element.first, element.second});}

#endif //MODCREATER_CDDA_MACRO_H
