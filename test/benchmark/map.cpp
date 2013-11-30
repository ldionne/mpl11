/*!
 * @file
 * Comparison of techniques to implement lookup in compile-time maps.
 */

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <typename T>
struct no_decay {
    using type = T;
};

template <typename First, typename Second>
struct pair;


// #define USE_MULTIPLE_INHERITANCE
#define USE_SINGLE_INHERITANCE

#ifdef USE_MULTIPLE_INHERITANCE

    template <typename Pair>
    struct holder { };

    template <typename ...Pairs>
    struct map : holder<Pairs>... {
    private:
        template <typename Key, typename Value>
        static no_decay<Value> at_key_impl(holder<pair<Key, Value>>*);

    public:
        template <typename Key>
        struct at_key
            : decltype(map::at_key_impl<Key>((map*)nullptr))
        { };
    };

#elif defined(USE_SINGLE_INHERITANCE)

    template <typename ...Pairs>
    struct map {
        template <typename Key>
        static typename Key::error_not_found at_key_impl(no_decay<Key>*);
    };

    template <typename Key, typename Value, typename ...Rest>
    struct map<pair<Key, Value>, Rest...> : map<Rest...> {
        using map<Rest...>::at_key_impl;
        static no_decay<Value> at_key_impl(no_decay<Key>*);

        template <typename K>
        struct at_key
            : decltype(map::at_key_impl((no_decay<K>*)nullptr))
        { };
    };

#endif

template <int> struct k;
template <int> struct v;
template <int Key, int Value> using kv = pair<k<Key>, v<Value>>;

static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<0>>::type,
    v<0>
>::value, "");
static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<1>>::type,
    v<1>
>::value, "");


/*
The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null map.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null map.cpp -ftemplate-depth=1000
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null map.cpp

Commands were ran 5 times and the average was taken.


                         | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
--------------------------------------------------------------------------------------------------
USE_MULTIPLE_INHERITANCE |    0.05s   |         0.03s        |               0.05s               |
USE_SINGLE_INHERITANCE   |    0.21s   |         0.98s(*)     |               63.41s(**)          |

(*) Template depth modification is required to avoid hitting the recursive template instantiation limit.
(**) This one was benchmarked only once. LOL

*/

// ruby -e "puts (0..500).collect{|i| \"kv<#{i}, #{i}>\"}.join(', ')" | pbcopy
static_assert(is_same<
    map<
        kv<0, 0>, kv<1, 1>, kv<2, 2>, kv<3, 3>, kv<4, 4>, kv<5, 5>, kv<6, 6>, kv<7, 7>, kv<8, 8>, kv<9, 9>, kv<10, 10>, kv<11, 11>, kv<12, 12>, kv<13, 13>, kv<14, 14>, kv<15, 15>, kv<16, 16>, kv<17, 17>, kv<18, 18>, kv<19, 19>, kv<20, 20>, kv<21, 21>, kv<22, 22>, kv<23, 23>, kv<24, 24>, kv<25, 25>, kv<26, 26>, kv<27, 27>, kv<28, 28>, kv<29, 29>, kv<30, 30>, kv<31, 31>, kv<32, 32>, kv<33, 33>, kv<34, 34>, kv<35, 35>, kv<36, 36>, kv<37, 37>, kv<38, 38>, kv<39, 39>, kv<40, 40>, kv<41, 41>, kv<42, 42>, kv<43, 43>, kv<44, 44>, kv<45, 45>, kv<46, 46>, kv<47, 47>, kv<48, 48>, kv<49, 49>, kv<50, 50>, kv<51, 51>, kv<52, 52>, kv<53, 53>, kv<54, 54>, kv<55, 55>, kv<56, 56>, kv<57, 57>, kv<58, 58>, kv<59, 59>, kv<60, 60>, kv<61, 61>, kv<62, 62>, kv<63, 63>, kv<64, 64>, kv<65, 65>, kv<66, 66>, kv<67, 67>, kv<68, 68>, kv<69, 69>, kv<70, 70>, kv<71, 71>, kv<72, 72>, kv<73, 73>, kv<74, 74>, kv<75, 75>, kv<76, 76>, kv<77, 77>, kv<78, 78>, kv<79, 79>, kv<80, 80>, kv<81, 81>, kv<82, 82>, kv<83, 83>, kv<84, 84>, kv<85, 85>, kv<86, 86>, kv<87, 87>, kv<88, 88>, kv<89, 89>, kv<90, 90>, kv<91, 91>, kv<92, 92>, kv<93, 93>, kv<94, 94>, kv<95, 95>, kv<96, 96>, kv<97, 97>, kv<98, 98>, kv<99, 99>, kv<100, 100>, kv<101, 101>, kv<102, 102>, kv<103, 103>, kv<104, 104>, kv<105, 105>, kv<106, 106>, kv<107, 107>, kv<108, 108>, kv<109, 109>, kv<110, 110>, kv<111, 111>, kv<112, 112>, kv<113, 113>, kv<114, 114>, kv<115, 115>, kv<116, 116>, kv<117, 117>, kv<118, 118>, kv<119, 119>, kv<120, 120>, kv<121, 121>, kv<122, 122>, kv<123, 123>, kv<124, 124>, kv<125, 125>, kv<126, 126>, kv<127, 127>, kv<128, 128>, kv<129, 129>, kv<130, 130>, kv<131, 131>, kv<132, 132>, kv<133, 133>, kv<134, 134>, kv<135, 135>, kv<136, 136>, kv<137, 137>, kv<138, 138>, kv<139, 139>, kv<140, 140>, kv<141, 141>, kv<142, 142>, kv<143, 143>, kv<144, 144>, kv<145, 145>, kv<146, 146>, kv<147, 147>, kv<148, 148>, kv<149, 149>, kv<150, 150>, kv<151, 151>, kv<152, 152>, kv<153, 153>, kv<154, 154>, kv<155, 155>, kv<156, 156>, kv<157, 157>, kv<158, 158>, kv<159, 159>, kv<160, 160>, kv<161, 161>, kv<162, 162>, kv<163, 163>, kv<164, 164>, kv<165, 165>, kv<166, 166>, kv<167, 167>, kv<168, 168>, kv<169, 169>, kv<170, 170>, kv<171, 171>, kv<172, 172>, kv<173, 173>, kv<174, 174>, kv<175, 175>, kv<176, 176>, kv<177, 177>, kv<178, 178>, kv<179, 179>, kv<180, 180>, kv<181, 181>, kv<182, 182>, kv<183, 183>, kv<184, 184>, kv<185, 185>, kv<186, 186>, kv<187, 187>, kv<188, 188>, kv<189, 189>, kv<190, 190>, kv<191, 191>, kv<192, 192>, kv<193, 193>, kv<194, 194>, kv<195, 195>, kv<196, 196>, kv<197, 197>, kv<198, 198>, kv<199, 199>, kv<200, 200>, kv<201, 201>, kv<202, 202>, kv<203, 203>, kv<204, 204>, kv<205, 205>, kv<206, 206>, kv<207, 207>, kv<208, 208>, kv<209, 209>, kv<210, 210>, kv<211, 211>, kv<212, 212>, kv<213, 213>, kv<214, 214>, kv<215, 215>, kv<216, 216>, kv<217, 217>, kv<218, 218>, kv<219, 219>, kv<220, 220>, kv<221, 221>, kv<222, 222>, kv<223, 223>, kv<224, 224>, kv<225, 225>, kv<226, 226>, kv<227, 227>, kv<228, 228>, kv<229, 229>, kv<230, 230>, kv<231, 231>, kv<232, 232>, kv<233, 233>, kv<234, 234>, kv<235, 235>, kv<236, 236>, kv<237, 237>, kv<238, 238>, kv<239, 239>, kv<240, 240>, kv<241, 241>, kv<242, 242>, kv<243, 243>, kv<244, 244>, kv<245, 245>, kv<246, 246>, kv<247, 247>, kv<248, 248>, kv<249, 249>, kv<250, 250>, kv<251, 251>, kv<252, 252>, kv<253, 253>, kv<254, 254>, kv<255, 255>, kv<256, 256>, kv<257, 257>, kv<258, 258>, kv<259, 259>, kv<260, 260>, kv<261, 261>, kv<262, 262>, kv<263, 263>, kv<264, 264>, kv<265, 265>, kv<266, 266>, kv<267, 267>, kv<268, 268>, kv<269, 269>, kv<270, 270>, kv<271, 271>, kv<272, 272>, kv<273, 273>, kv<274, 274>, kv<275, 275>, kv<276, 276>, kv<277, 277>, kv<278, 278>, kv<279, 279>, kv<280, 280>, kv<281, 281>, kv<282, 282>, kv<283, 283>, kv<284, 284>, kv<285, 285>, kv<286, 286>, kv<287, 287>, kv<288, 288>, kv<289, 289>, kv<290, 290>, kv<291, 291>, kv<292, 292>, kv<293, 293>, kv<294, 294>, kv<295, 295>, kv<296, 296>, kv<297, 297>, kv<298, 298>, kv<299, 299>, kv<300, 300>, kv<301, 301>, kv<302, 302>, kv<303, 303>, kv<304, 304>, kv<305, 305>, kv<306, 306>, kv<307, 307>, kv<308, 308>, kv<309, 309>, kv<310, 310>, kv<311, 311>, kv<312, 312>, kv<313, 313>, kv<314, 314>, kv<315, 315>, kv<316, 316>, kv<317, 317>, kv<318, 318>, kv<319, 319>, kv<320, 320>, kv<321, 321>, kv<322, 322>, kv<323, 323>, kv<324, 324>, kv<325, 325>, kv<326, 326>, kv<327, 327>, kv<328, 328>, kv<329, 329>, kv<330, 330>, kv<331, 331>, kv<332, 332>, kv<333, 333>, kv<334, 334>, kv<335, 335>, kv<336, 336>, kv<337, 337>, kv<338, 338>, kv<339, 339>, kv<340, 340>, kv<341, 341>, kv<342, 342>, kv<343, 343>, kv<344, 344>, kv<345, 345>, kv<346, 346>, kv<347, 347>, kv<348, 348>, kv<349, 349>, kv<350, 350>, kv<351, 351>, kv<352, 352>, kv<353, 353>, kv<354, 354>, kv<355, 355>, kv<356, 356>, kv<357, 357>, kv<358, 358>, kv<359, 359>, kv<360, 360>, kv<361, 361>, kv<362, 362>, kv<363, 363>, kv<364, 364>, kv<365, 365>, kv<366, 366>, kv<367, 367>, kv<368, 368>, kv<369, 369>, kv<370, 370>, kv<371, 371>, kv<372, 372>, kv<373, 373>, kv<374, 374>, kv<375, 375>, kv<376, 376>, kv<377, 377>, kv<378, 378>, kv<379, 379>, kv<380, 380>, kv<381, 381>, kv<382, 382>, kv<383, 383>, kv<384, 384>, kv<385, 385>, kv<386, 386>, kv<387, 387>, kv<388, 388>, kv<389, 389>, kv<390, 390>, kv<391, 391>, kv<392, 392>, kv<393, 393>, kv<394, 394>, kv<395, 395>, kv<396, 396>, kv<397, 397>, kv<398, 398>, kv<399, 399>, kv<400, 400>, kv<401, 401>, kv<402, 402>, kv<403, 403>, kv<404, 404>, kv<405, 405>, kv<406, 406>, kv<407, 407>, kv<408, 408>, kv<409, 409>, kv<410, 410>, kv<411, 411>, kv<412, 412>, kv<413, 413>, kv<414, 414>, kv<415, 415>, kv<416, 416>, kv<417, 417>, kv<418, 418>, kv<419, 419>, kv<420, 420>, kv<421, 421>, kv<422, 422>, kv<423, 423>, kv<424, 424>, kv<425, 425>, kv<426, 426>, kv<427, 427>, kv<428, 428>, kv<429, 429>, kv<430, 430>, kv<431, 431>, kv<432, 432>, kv<433, 433>, kv<434, 434>, kv<435, 435>, kv<436, 436>, kv<437, 437>, kv<438, 438>, kv<439, 439>, kv<440, 440>, kv<441, 441>, kv<442, 442>, kv<443, 443>, kv<444, 444>, kv<445, 445>, kv<446, 446>, kv<447, 447>, kv<448, 448>, kv<449, 449>, kv<450, 450>, kv<451, 451>, kv<452, 452>, kv<453, 453>, kv<454, 454>, kv<455, 455>, kv<456, 456>, kv<457, 457>, kv<458, 458>, kv<459, 459>, kv<460, 460>, kv<461, 461>, kv<462, 462>, kv<463, 463>, kv<464, 464>, kv<465, 465>, kv<466, 466>, kv<467, 467>, kv<468, 468>, kv<469, 469>, kv<470, 470>, kv<471, 471>, kv<472, 472>, kv<473, 473>, kv<474, 474>, kv<475, 475>, kv<476, 476>, kv<477, 477>, kv<478, 478>, kv<479, 479>, kv<480, 480>, kv<481, 481>, kv<482, 482>, kv<483, 483>, kv<484, 484>, kv<485, 485>, kv<486, 486>, kv<487, 487>, kv<488, 488>, kv<489, 489>, kv<490, 490>, kv<491, 491>, kv<492, 492>, kv<493, 493>, kv<494, 494>, kv<495, 495>, kv<496, 496>, kv<497, 497>, kv<498, 498>, kv<499, 499>, kv<500, 500>
    >::at_key<k<500>>::type,
    v<500>
>::value, "");


int main() { }
