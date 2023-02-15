//#ifndef CREATE_GREEDY_HPP
//#define CREATE_GREEDY_HPP

//#include "array.hpp"
//#include "../../../onion/create.hpp"

//namespace onion{
//namespace cops {
//namespace tsp {
//namespace array {

//template<typename problem_data_t,unsigned int num_cities>
//class CreateGreedy : public onion::CreateOperator< solution_t<num_cities> >
//{
//public:

//    CreateGreedy(const problem_data_t& data):
//        _data(data),
//        Component( SetComponent()
//                    .name("CreateGreedy")
//                    .description("Starts at a random city then move to the closest city recursively until all cities are visited.")
//                    .type("Create Operator")
//                    .version("v0.1.0")
//                    .problem("TSP")
//                    .solution_type("unsigned int[]")
//                   ){

//    }

//    virtual solution_t<num_cities> operator()(void){

//        // creates a path, always choosing the closest city available
//        static const unsigned  n = static_cast<unsigned>( _data.size() );
//        static solution_t<num_cities>          visited(n+1,0);

//        auto city       = onion::rand_between(0,n-1);
//        visited.at(0)   = city;

//        for(unsigned i = 1; i < n; i++){
//            // get the city that has, at the same time,
//            //the minimum travel cost and was not visited yet
//            unsigned least_cost         = std::numeric_limits<unsigned>::max();
//            unsigned least_cost_city    = 0;

//            for(unsigned j = 0; j < n; j++){
//               auto end = visited.begin()+i;
//               if ( std::find(visited.begin(), end, j ) != end ) continue; // O(N)!! can be O(1)

//               if ( _data.at(city).at(j) < least_cost ){
//                   least_cost = _data.at(city).at(j);
//                   least_cost_city = j;
//               }
//            }
//            visited.at(i)   = least_cost_city;
//            city            = least_cost_city;
//        }

//        static path_t res(n+1,0);

//        // path starts at a random city.
//        // This puts back in the 0 starting standard
//        // this is just me being afraid of some algorithm
//        // relying on paths starting always at city 0

//        // CONSIDER REMOVING

//        if ( visited.at(0) != 0 ){

//            auto it = std::find(visited.begin(),visited.end(),0);
//            auto len = std::distance(it,visited.end());

//            std::copy(it,visited.end(),res.begin());
//            std::copy(visited.begin(),it,res.begin()+len-1);
//        }
//        else{
//            res = visited;
//        }

//        return res;

//    }
//private:

//    problem_data_t _data;
//};

//#endif // CREATE_GREEDY_HPP
