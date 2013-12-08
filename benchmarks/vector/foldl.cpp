/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c foldl.cpp -ftemplate-depth=1000
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c foldl.cpp -ftemplate-depth=1000
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c foldl.cpp -ftemplate-depth=1000

Commands were ran 5 times and the average was taken.

vector of size 50      | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
-------------------------------------------------------------------------------------------------
USE_MPL11              |    0.13s    |         0.07s        |               0.09s               |
USE_MPL                |    0.27s    |         0.15s        |               0.27s               |


vector of size 500 [1] | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
-------------------------------------------------------------------------------------------------
USE_MPL11              |    0.41s    |         0.40s        |               0.27s               |
USE_MPL                |    1.33s    |         0.60s        |               1.39s               |

*/

// #define USE_MPL11
#define USE_MPL

// #define VECTOR_SIZE_50
#define VECTOR_SIZE_500

#if defined(USE_MPL11)

    #include <boost/mpl11/foldl.hpp>
    #include <boost/mpl11/vector.hpp>

    using boost::mpl11::vector;

    template <typename Sequence, typename State, typename F>
    using fold = boost::mpl11::foldl<Sequence, State, F>;

#elif defined(USE_MPL)

    #if defined(VECTOR_SIZE_500)

        #include <boost/mpl/fold.hpp>
        #include <boost/mpl/joint_view.hpp>
        #include <boost/mpl/vector.hpp>
        #include <boost/mpl/vector/vector50.hpp>

        template <typename ...T>
        struct make_vector {
            using type = boost::mpl::vector<T...>;
        };

        // ruby -e "puts 50.times.collect{|i| \"typename A#{i}\"}.join(', ')" | pbcopy
        template <
            typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49
        , typename ...Rest>
        struct make_vector<
            // ruby -e "puts 50.times.collect{|i| \"A#{i}\"}.join(', ')" | pbcopy
            A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49
            , Rest...
        > {
            using type = boost::mpl::joint_view<
                boost::mpl::vector50<
                    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49
                >,
                typename make_vector<Rest...>::type
            >;
        };

        template <typename ...T>
        using vector = typename make_vector<T...>::type;
        using boost::mpl::fold;

    #elif defined(VECTOR_SIZE_50)

        #include <boost/mpl/vector/vector50.hpp>
        #include <boost/mpl/fold.hpp>

        template <typename ...T>
        using vector = boost::mpl::vector50<T...>;
        using boost::mpl::fold;

    #endif

#endif


template <int> struct x;

#if defined(VECTOR_SIZE_50)

    // ruby -e "puts 50.times.collect{|i| \"x<#{i}>\"}.join(', ')" | pbcopy
    using Vector = vector<
        x<0>, x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>, x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>, x<19>, x<20>, x<21>, x<22>, x<23>, x<24>, x<25>, x<26>, x<27>, x<28>, x<29>, x<30>, x<31>, x<32>, x<33>, x<34>, x<35>, x<36>, x<37>, x<38>, x<39>, x<40>, x<41>, x<42>, x<43>, x<44>, x<45>, x<46>, x<47>, x<48>, x<49>
    >;

#elif defined(VECTOR_SIZE_500)

    // ruby -e "puts 500.times.collect{|i| \"x<#{i}>\"}.join(', ')" | pbcopy
    using Vector = vector<
        x<0>, x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>, x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>, x<19>, x<20>, x<21>, x<22>, x<23>, x<24>, x<25>, x<26>, x<27>, x<28>, x<29>, x<30>, x<31>, x<32>, x<33>, x<34>, x<35>, x<36>, x<37>, x<38>, x<39>, x<40>, x<41>, x<42>, x<43>, x<44>, x<45>, x<46>, x<47>, x<48>, x<49>, x<50>, x<51>, x<52>, x<53>, x<54>, x<55>, x<56>, x<57>, x<58>, x<59>, x<60>, x<61>, x<62>, x<63>, x<64>, x<65>, x<66>, x<67>, x<68>, x<69>, x<70>, x<71>, x<72>, x<73>, x<74>, x<75>, x<76>, x<77>, x<78>, x<79>, x<80>, x<81>, x<82>, x<83>, x<84>, x<85>, x<86>, x<87>, x<88>, x<89>, x<90>, x<91>, x<92>, x<93>, x<94>, x<95>, x<96>, x<97>, x<98>, x<99>, x<100>, x<101>, x<102>, x<103>, x<104>, x<105>, x<106>, x<107>, x<108>, x<109>, x<110>, x<111>, x<112>, x<113>, x<114>, x<115>, x<116>, x<117>, x<118>, x<119>, x<120>, x<121>, x<122>, x<123>, x<124>, x<125>, x<126>, x<127>, x<128>, x<129>, x<130>, x<131>, x<132>, x<133>, x<134>, x<135>, x<136>, x<137>, x<138>, x<139>, x<140>, x<141>, x<142>, x<143>, x<144>, x<145>, x<146>, x<147>, x<148>, x<149>, x<150>, x<151>, x<152>, x<153>, x<154>, x<155>, x<156>, x<157>, x<158>, x<159>, x<160>, x<161>, x<162>, x<163>, x<164>, x<165>, x<166>, x<167>, x<168>, x<169>, x<170>, x<171>, x<172>, x<173>, x<174>, x<175>, x<176>, x<177>, x<178>, x<179>, x<180>, x<181>, x<182>, x<183>, x<184>, x<185>, x<186>, x<187>, x<188>, x<189>, x<190>, x<191>, x<192>, x<193>, x<194>, x<195>, x<196>, x<197>, x<198>, x<199>, x<200>, x<201>, x<202>, x<203>, x<204>, x<205>, x<206>, x<207>, x<208>, x<209>, x<210>, x<211>, x<212>, x<213>, x<214>, x<215>, x<216>, x<217>, x<218>, x<219>, x<220>, x<221>, x<222>, x<223>, x<224>, x<225>, x<226>, x<227>, x<228>, x<229>, x<230>, x<231>, x<232>, x<233>, x<234>, x<235>, x<236>, x<237>, x<238>, x<239>, x<240>, x<241>, x<242>, x<243>, x<244>, x<245>, x<246>, x<247>, x<248>, x<249>, x<250>, x<251>, x<252>, x<253>, x<254>, x<255>, x<256>, x<257>, x<258>, x<259>, x<260>, x<261>, x<262>, x<263>, x<264>, x<265>, x<266>, x<267>, x<268>, x<269>, x<270>, x<271>, x<272>, x<273>, x<274>, x<275>, x<276>, x<277>, x<278>, x<279>, x<280>, x<281>, x<282>, x<283>, x<284>, x<285>, x<286>, x<287>, x<288>, x<289>, x<290>, x<291>, x<292>, x<293>, x<294>, x<295>, x<296>, x<297>, x<298>, x<299>, x<300>, x<301>, x<302>, x<303>, x<304>, x<305>, x<306>, x<307>, x<308>, x<309>, x<310>, x<311>, x<312>, x<313>, x<314>, x<315>, x<316>, x<317>, x<318>, x<319>, x<320>, x<321>, x<322>, x<323>, x<324>, x<325>, x<326>, x<327>, x<328>, x<329>, x<330>, x<331>, x<332>, x<333>, x<334>, x<335>, x<336>, x<337>, x<338>, x<339>, x<340>, x<341>, x<342>, x<343>, x<344>, x<345>, x<346>, x<347>, x<348>, x<349>, x<350>, x<351>, x<352>, x<353>, x<354>, x<355>, x<356>, x<357>, x<358>, x<359>, x<360>, x<361>, x<362>, x<363>, x<364>, x<365>, x<366>, x<367>, x<368>, x<369>, x<370>, x<371>, x<372>, x<373>, x<374>, x<375>, x<376>, x<377>, x<378>, x<379>, x<380>, x<381>, x<382>, x<383>, x<384>, x<385>, x<386>, x<387>, x<388>, x<389>, x<390>, x<391>, x<392>, x<393>, x<394>, x<395>, x<396>, x<397>, x<398>, x<399>, x<400>, x<401>, x<402>, x<403>, x<404>, x<405>, x<406>, x<407>, x<408>, x<409>, x<410>, x<411>, x<412>, x<413>, x<414>, x<415>, x<416>, x<417>, x<418>, x<419>, x<420>, x<421>, x<422>, x<423>, x<424>, x<425>, x<426>, x<427>, x<428>, x<429>, x<430>, x<431>, x<432>, x<433>, x<434>, x<435>, x<436>, x<437>, x<438>, x<439>, x<440>, x<441>, x<442>, x<443>, x<444>, x<445>, x<446>, x<447>, x<448>, x<449>, x<450>, x<451>, x<452>, x<453>, x<454>, x<455>, x<456>, x<457>, x<458>, x<459>, x<460>, x<461>, x<462>, x<463>, x<464>, x<465>, x<466>, x<467>, x<468>, x<469>, x<470>, x<471>, x<472>, x<473>, x<474>, x<475>, x<476>, x<477>, x<478>, x<479>, x<480>, x<481>, x<482>, x<483>, x<484>, x<485>, x<486>, x<487>, x<488>, x<489>, x<490>, x<491>, x<492>, x<493>, x<494>, x<495>, x<496>, x<497>, x<498>, x<499>
    >;

#endif

struct f { template <typename, typename> struct apply { struct type; }; };
using Go = fold<Vector, struct dummy, f>::type;


int main() { }
