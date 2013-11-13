
#ifdef USE_MPL11
    #include <boost/mpl11/vector.hpp>
    #include <boost/mpl11/at.hpp>
    namespace mpl = boost::mpl11;
    #define MPL_VECTOR mpl::vector
#else
    #include <boost/mpl/vector/vector50.hpp>
    #include <boost/mpl/at.hpp>
    namespace mpl = boost::mpl;
    #define MPL_VECTOR mpl::vector50
#endif

/******
#!/usr/bin/env ruby
puts 50.times.collect{|i| "x<#{i}>"}.join(', ')
*******/

template <int> struct x;

using Vector = MPL_VECTOR<
    x<0>, x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>, x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>, x<19>, x<20>, x<21>, x<22>, x<23>, x<24>, x<25>, x<26>, x<27>, x<28>, x<29>, x<30>, x<31>, x<32>, x<33>, x<34>, x<35>, x<36>, x<37>, x<38>, x<39>, x<40>, x<41>, x<42>, x<43>, x<44>, x<45>, x<46>, x<47>, x<48>, x<49>
>;
using Test = mpl::at_c<Vector, 49>::type;


int main() { }
