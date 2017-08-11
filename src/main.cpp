#include "VirtualCopyConstructor.h"

#include <vector>
#include <random>
#include <typeinfo>
 
int main(int argc, char * argv[])
{

    std::random_device      rd;             //  Needed to obtain a seed for the random number engine
    std::mt19937            gen(rd());      //  Standard mersenee_twister_engine seeded with rd()
    std::uniform_int_distribution<>     
                            unif_dist(1,2);

    Factory factory;

    std::vector<Base*> originals;
    std::vector<Base*> clones;

    try {

        for (int i = 0; i<10; ++i)
        {
            int rn = unif_dist(gen);

            int value = rn == 1? 10 : 20;
            
            originals.push_back(factory.create(rn, value));
        }

        //  cloning    
        for (auto o : originals)
            clones.push_back(o->clone());


        {
            std::cout<<"Originals\n"
                       "============\n";

            for (auto o : originals)
                o->print();

            std::cout<<"============\n";
        }

        {
            std::cout<<"\nClones\n"
                       "============\n";

            for (auto c : clones)
                c->print();

            std::cout<<"============\n";
        }
    
        //  testing for correct cloning
        std::cout<<"\nTesting for correct cloning\n"
                     "===========================\n";
        
        for (int i = 0; i<originals.size(); i++)
        {
            if (typeid(*originals[i]) == typeid(*clones[i]))
                std::cout <<"OK, " <<typeid(*originals[i]).name()<< " was cloned successfully\n";
            else
                std::cout <<"Cloning of "<< typeid(*originals[i]).name() <<" Failed;\n";
        }
        std::cout<<"\n";
    }
    catch(std::string msg)
    {
        std::cout <<"Exception occured: msg: "<<msg<<"\n";
    }


    // cleaning up
    for (auto c : clones)  delete c;
    for (auto o : originals)  delete o;

}

