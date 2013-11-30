/*!
 * @file
 * Comparison of techniques to implement access to parameter packs.
 */

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <unsigned... I>
struct index_sequence;

template <typename Left, typename Right>
struct concat_indices;

template <unsigned... Left, unsigned... Right>
struct concat_indices<index_sequence<Left...>, index_sequence<Right...>> {
    using type = index_sequence<Left..., (sizeof...(Left) + Right)...>;
};

template <unsigned N>
struct make_index_sequence
    : concat_indices<
        typename make_index_sequence<N / 2>::type,
        typename make_index_sequence<N - N / 2>::type
    >
{ };

template <> struct make_index_sequence<0> { using type = index_sequence<>; };
template <> struct make_index_sequence<1> { using type = index_sequence<0>; };
template <> struct make_index_sequence<2> { using type = index_sequence<0, 1>; };

#define EXPLICITLY_INSTANTIATE_INDEX_SEQUENCE
#define USE_OVERLOAD
// #define USE_MULTIPLE_INHERITANCE


// Since this utility could be used elsewhere in the program, it should not
// contribute to the measured difference between the implementations below.
// To make sure it does not, we explicitly instantiate it regardless of the
// technique we're using below.
#ifdef EXPLICITLY_INSTANTIATE_INDEX_SEQUENCE
    template struct make_index_sequence<1000>;
#endif

#if defined(USE_OVERLOAD)

    template <typename T>
    struct no_decay;

    template <typename Head>
    struct at_impl;

    template <unsigned ...Head>
    struct at_impl<index_sequence<Head...>> {
        template <typename Nth>
        static Nth apply(decltype((Head, (void*)0))..., no_decay<Nth>*, ...);
    };

    template <unsigned N, typename ...Args>
    struct at {
        using type = decltype(
            at_impl<typename make_index_sequence<N>::type>::apply(
                (no_decay<Args>*)nullptr...
            )
        );
    };

#elif defined(USE_MULTIPLE_INHERITANCE)

    template <typename T>
    struct no_decay {
        using type = T;
    };

    template <unsigned Index, typename Value>
    struct holder { };

    template <typename Indices, typename ...T>
    struct vector;

    template <unsigned ...Indices, typename ...T>
    struct vector<index_sequence<Indices...>, T...> : holder<Indices, T>... {
        template <unsigned Index, typename Value>
        static no_decay<Value> at_impl(holder<Index, Value>*);
    };

    template <unsigned N, typename ...Args>
    struct at {
        using Vector = vector<
            typename make_index_sequence<sizeof...(Args)>::type, Args...
        >;
        using type = typename decltype(
            Vector::template at_impl<N>((Vector*)nullptr)
        )::type;
    };

#endif

template <unsigned> struct t;

static_assert(is_same<at<0, t<0>>::type, t<0>>::value, "");
static_assert(is_same<at<0, t<0>, t<1>>::type, t<0>>::value, "");
static_assert(is_same<at<0, t<0>, t<1>, t<2>>::type, t<0>>::value, "");

static_assert(is_same<at<1, t<0>, t<1>>::type, t<1>>::value, "");
static_assert(is_same<at<1, t<0>, t<1>, t<2>>::type, t<1>>::value, "");
static_assert(is_same<at<1, t<0>, t<1>, t<2>, t<3>>::type, t<1>>::value, "");

static_assert(is_same<at<2, t<0>, t<1>, t<2>>::type, t<2>>::value, "");
static_assert(is_same<at<2, t<0>, t<1>, t<2>, t<3>>::type, t<2>>::value, "");
static_assert(is_same<at<2, t<0>, t<1>, t<2>, t<3>, t<4>>::type, t<2>>::value, "");


/*
The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null at.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null at.cpp
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null at.cpp

Commands were ran 5 times and the average was taken.


With EXPLICITLY_INSTANTIATE_INDEX_SEQUENCE:

                         | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.07s   |         0.04s        |               0.09s               |
USE_MULTIPLE_INHERITANCE |    0.09s   |         0.04s        |               0.11s               |
--------------------------------------------------------------------------------------------------


Without EXPLICITLY_INSTANTIATE_INDEX_SEQUENCE:

                         | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.06s   |         0.03s        |               0.06s               |
USE_MULTIPLE_INHERITANCE |    0.07s   |         0.03s        |               0.07s               |

*/


// ruby -e "puts (0..500).collect{|i| \"t<#{i}>\"}.join(', ')" | pbcopy
static_assert(is_same<
    at<500,
        t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>, t<30>, t<31>, t<32>, t<33>, t<34>, t<35>, t<36>, t<37>, t<38>, t<39>, t<40>, t<41>, t<42>, t<43>, t<44>, t<45>, t<46>, t<47>, t<48>, t<49>, t<50>, t<51>, t<52>, t<53>, t<54>, t<55>, t<56>, t<57>, t<58>, t<59>, t<60>, t<61>, t<62>, t<63>, t<64>, t<65>, t<66>, t<67>, t<68>, t<69>, t<70>, t<71>, t<72>, t<73>, t<74>, t<75>, t<76>, t<77>, t<78>, t<79>, t<80>, t<81>, t<82>, t<83>, t<84>, t<85>, t<86>, t<87>, t<88>, t<89>, t<90>, t<91>, t<92>, t<93>, t<94>, t<95>, t<96>, t<97>, t<98>, t<99>, t<100>, t<101>, t<102>, t<103>, t<104>, t<105>, t<106>, t<107>, t<108>, t<109>, t<110>, t<111>, t<112>, t<113>, t<114>, t<115>, t<116>, t<117>, t<118>, t<119>, t<120>, t<121>, t<122>, t<123>, t<124>, t<125>, t<126>, t<127>, t<128>, t<129>, t<130>, t<131>, t<132>, t<133>, t<134>, t<135>, t<136>, t<137>, t<138>, t<139>, t<140>, t<141>, t<142>, t<143>, t<144>, t<145>, t<146>, t<147>, t<148>, t<149>, t<150>, t<151>, t<152>, t<153>, t<154>, t<155>, t<156>, t<157>, t<158>, t<159>, t<160>, t<161>, t<162>, t<163>, t<164>, t<165>, t<166>, t<167>, t<168>, t<169>, t<170>, t<171>, t<172>, t<173>, t<174>, t<175>, t<176>, t<177>, t<178>, t<179>, t<180>, t<181>, t<182>, t<183>, t<184>, t<185>, t<186>, t<187>, t<188>, t<189>, t<190>, t<191>, t<192>, t<193>, t<194>, t<195>, t<196>, t<197>, t<198>, t<199>, t<200>, t<201>, t<202>, t<203>, t<204>, t<205>, t<206>, t<207>, t<208>, t<209>, t<210>, t<211>, t<212>, t<213>, t<214>, t<215>, t<216>, t<217>, t<218>, t<219>, t<220>, t<221>, t<222>, t<223>, t<224>, t<225>, t<226>, t<227>, t<228>, t<229>, t<230>, t<231>, t<232>, t<233>, t<234>, t<235>, t<236>, t<237>, t<238>, t<239>, t<240>, t<241>, t<242>, t<243>, t<244>, t<245>, t<246>, t<247>, t<248>, t<249>, t<250>, t<251>, t<252>, t<253>, t<254>, t<255>, t<256>, t<257>, t<258>, t<259>, t<260>, t<261>, t<262>, t<263>, t<264>, t<265>, t<266>, t<267>, t<268>, t<269>, t<270>, t<271>, t<272>, t<273>, t<274>, t<275>, t<276>, t<277>, t<278>, t<279>, t<280>, t<281>, t<282>, t<283>, t<284>, t<285>, t<286>, t<287>, t<288>, t<289>, t<290>, t<291>, t<292>, t<293>, t<294>, t<295>, t<296>, t<297>, t<298>, t<299>, t<300>, t<301>, t<302>, t<303>, t<304>, t<305>, t<306>, t<307>, t<308>, t<309>, t<310>, t<311>, t<312>, t<313>, t<314>, t<315>, t<316>, t<317>, t<318>, t<319>, t<320>, t<321>, t<322>, t<323>, t<324>, t<325>, t<326>, t<327>, t<328>, t<329>, t<330>, t<331>, t<332>, t<333>, t<334>, t<335>, t<336>, t<337>, t<338>, t<339>, t<340>, t<341>, t<342>, t<343>, t<344>, t<345>, t<346>, t<347>, t<348>, t<349>, t<350>, t<351>, t<352>, t<353>, t<354>, t<355>, t<356>, t<357>, t<358>, t<359>, t<360>, t<361>, t<362>, t<363>, t<364>, t<365>, t<366>, t<367>, t<368>, t<369>, t<370>, t<371>, t<372>, t<373>, t<374>, t<375>, t<376>, t<377>, t<378>, t<379>, t<380>, t<381>, t<382>, t<383>, t<384>, t<385>, t<386>, t<387>, t<388>, t<389>, t<390>, t<391>, t<392>, t<393>, t<394>, t<395>, t<396>, t<397>, t<398>, t<399>, t<400>, t<401>, t<402>, t<403>, t<404>, t<405>, t<406>, t<407>, t<408>, t<409>, t<410>, t<411>, t<412>, t<413>, t<414>, t<415>, t<416>, t<417>, t<418>, t<419>, t<420>, t<421>, t<422>, t<423>, t<424>, t<425>, t<426>, t<427>, t<428>, t<429>, t<430>, t<431>, t<432>, t<433>, t<434>, t<435>, t<436>, t<437>, t<438>, t<439>, t<440>, t<441>, t<442>, t<443>, t<444>, t<445>, t<446>, t<447>, t<448>, t<449>, t<450>, t<451>, t<452>, t<453>, t<454>, t<455>, t<456>, t<457>, t<458>, t<459>, t<460>, t<461>, t<462>, t<463>, t<464>, t<465>, t<466>, t<467>, t<468>, t<469>, t<470>, t<471>, t<472>, t<473>, t<474>, t<475>, t<476>, t<477>, t<478>, t<479>, t<480>, t<481>, t<482>, t<483>, t<484>, t<485>, t<486>, t<487>, t<488>, t<489>, t<490>, t<491>, t<492>, t<493>, t<494>, t<495>, t<496>, t<497>, t<498>, t<499>, t<500>
    >::type,
    t<500>
>::value, "");


int main() { }
