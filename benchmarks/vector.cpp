/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector.cpp -ftemplate-depth=1000
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector.cpp -ftemplate-depth=1000
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -I ~/code/mpl11/include -c vector.cpp -ftemplate-depth=1000

Commands were ran 5 times and the average was taken.


foldl
-----

vector size = 50  | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
--------------------------------------------------------------------------------------------
mpl11             |   0.14s     |         0.07s        |             0.09s                 |
mpl               |   0.27s     |         0.15s        |             0.28s                 |

vector size = 100 |
--------------------------------------------------------------------------------------------
mpl11             |   0.15s     |         0.08s        |             0.09s                 |
mpl               |   0.38s     |         0.20s        |             0.36s                 |

vector size = 200 |
--------------------------------------------------------------------------------------------
mpl11             |   0.20s     |         0.14s        |             0.13s                 |
mpl               |   0.56s     |         0.28s        |             0.55s                 |

vector size = 400 |
--------------------------------------------------------------------------------------------
mpl11             |   0.34s     |         0.29s        |             0.22s                 |
mpl               |   1.05s     |         0.48s        |             1.05s                 |

vector size = 800 |
--------------------------------------------------------------------------------------------
mpl11             |   0.73s     |         0.88s        |             0.49s                 |
mpl               |   2.39s     |         1.06s        |             2.72s                 |



at (fetching last element)
--------------------------

vector size = 50  | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
--------------------------------------------------------------------------------------------
mpl11             |   0.12s     |         0.07s        |             0.08s                 |
mpl               |   0.18s     |         0.11s        |             0.21s                 |

vector size = 100 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 200 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 400 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 800 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |



pop_back
--------

vector size = 50  | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
--------------------------------------------------------------------------------------------
mpl11             |   0.12s     |         0.06s        |             0.08s                 |
mpl               |   0.15s     |         0.09s        |             0.18s                 |

vector size = 100 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 200 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 400 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

vector size = 800 |
--------------------------------------------------------------------------------------------
mpl11             |   0.xxs     |         0.xxs        |             0.xxs                 |
mpl               |   0.xxs     |         0.xxs        |             0.xxs                 |

*/


template <unsigned int> struct x;

// ruby -e "puts 100.times.collect{|i| \"x<#{i}>\"}.join(', ')" | pbcopy
#define VECTOR_SIZE 100
#define CONTENTS x<0>, x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>, x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>, x<19>, x<20>, x<21>, x<22>, x<23>, x<24>, x<25>, x<26>, x<27>, x<28>, x<29>, x<30>, x<31>, x<32>, x<33>, x<34>, x<35>, x<36>, x<37>, x<38>, x<39>, x<40>, x<41>, x<42>, x<43>, x<44>, x<45>, x<46>, x<47>, x<48>, x<49>, x<50>, x<51>, x<52>, x<53>, x<54>, x<55>, x<56>, x<57>, x<58>, x<59>, x<60>, x<61>, x<62>, x<63>, x<64>, x<65>, x<66>, x<67>, x<68>, x<69>, x<70>, x<71>, x<72>, x<73>, x<74>, x<75>, x<76>, x<77>, x<78>, x<79>, x<80>, x<81>, x<82>, x<83>, x<84>, x<85>, x<86>, x<87>, x<88>, x<89>, x<90>, x<91>, x<92>, x<93>, x<94>, x<95>, x<96>, x<97>, x<98>, x<99>


// #define USE_MPL11
#define USE_MPL

// #define FOLDL
// #define AT
// #define POP_BACK


#if defined(USE_MPL11)

    #include <boost/mpl11/vector.hpp>
    using DataSet = boost::mpl11::vector<CONTENTS>;

#elif defined(USE_MPL)

    #if VECTOR_SIZE <= 50

        #include <boost/mpl/vector/vector50.hpp>
        #define PP_CONCAT_PRIM(x, y) x ## y
        #define PP_CONCAT(x, y) PP_CONCAT_PRIM(x, y)
        using DataSet = PP_CONCAT(boost::mpl::vector, VECTOR_SIZE)<CONTENTS>;

    #else

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

        using DataSet = make_vector<CONTENTS>::type;

    #endif

#endif


#if defined(FOLDL)

    struct State;
    struct F { template <typename, typename> struct apply { struct type; }; };

    #if defined(USE_MPL11)
        #include <boost/mpl11/foldl.hpp>
        using Go = boost::mpl11::foldl<DataSet, State, F>::type;
    #else
        #include <boost/mpl/fold.hpp>
        using Go = boost::mpl::fold<DataSet, State, F>::type;
    #endif

#elif defined(AT)

    static constexpr unsigned long Index = VECTOR_SIZE - 1;

    #if defined(USE_MPL11)
        #include <boost/mpl11/at.hpp>
        using Go = boost::mpl11::at_c<DataSet, Index>::type;
    #else
        #include <boost/mpl/at.hpp>
        using Go = boost::mpl::at_c<DataSet, Index>::type;

    #endif

#elif defined(POP_BACK)

    #if defined(USE_MPL11)
        #include <boost/mpl11/pop_back.hpp>
        using Go = boost::mpl11::pop_back<DataSet>::type;
    #else
        #include <boost/mpl/pop_back.hpp>
        using Go = boost::mpl::pop_back<DataSet>::type;
    #endif

#endif


int main() { }
