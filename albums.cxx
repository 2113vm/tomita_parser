#encoding "utf-8"
#GRAMMAR_ROOT S

Language -> 'англ' | 'рус';
Brackets -> LBracket (Language) AnyWord* (Language) (AnyWord*) RBracket;
Album -> AnyWord* interp(Albums.Album) (Brackets interp(Albums.Translate)) Hyphen Adj;

FullName -> AnyWord<h-reg1>* AnyWord<h-reg1>;
Auth -> AnyWord * 'альбом'  AnyWord<l-reg>* FullName interp(Albums.Band) ',';

Date -> AnyWord<kwtype = "даты">;

S -> Album Auth  AnyWord*  Date interp(Albums.Date) (AnyWord *)( ',');
