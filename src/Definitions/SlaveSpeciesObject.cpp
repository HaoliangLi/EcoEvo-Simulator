/*
 * SlaveSpeciesObject.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: qiaohj
 */

#include "SlaveSpeciesObject.h"

SlaveSpeciesObject::SlaveSpeciesObject(Json::Value root) {
    id = root.get("id", "").asString();
    dispersalAbility = root.get("dispersal_ability", 1).asInt();
    dispersalSpeed = root.get("dispersal_speed", 1000).asInt();
    dispersalMethod = root.get("dispersal_method", 1).asInt();
    numberOfPath = root.get("number_of_path", -1).asInt();

    Json::Value niche_breadth_array = root["niche_breadth"];
    nicheBreadth.reserve(niche_breadth_array.size());
    for (unsigned index = 0; index < niche_breadth_array.size(); ++index){
        Json::Value niche_breadth_json = niche_breadth_array[index];
        float* niche_breadth = new float[2];
        for (unsigned i = 0; i < niche_breadth_json.size(); ++i){
            niche_breadth[i] = niche_breadth_json[i].asFloat();
        }
        nicheBreadth.push_back(niche_breadth);
    }

    Json::Value initial_seeds_array = root["initial_seeds"];
    initialSeeds.reserve(initial_seeds_array.size());
    for (unsigned index = 0; index < initial_seeds_array.size(); ++index){
        Json::Value initial_seeds_json = initial_seeds_array[index];
        float* initial_seed = new float[2];
        for (unsigned i = 0; i < initial_seeds_json.size(); ++i){
            initial_seed[i] = initial_seeds_json[i].asFloat();
        }
        initialSeeds.push_back(initial_seed);
    }
}

SlaveSpeciesObject::~SlaveSpeciesObject() {
    for (vector<float*>::iterator it = nicheBreadth.begin() ; it != nicheBreadth.end(); ++it){
        delete[] *it;
    }

    for (vector<float*>::iterator it = initialSeeds.begin() ; it != initialSeeds.end(); ++it){
        delete[] *it;
    }
    vector<float*>().swap(nicheBreadth);
    vector<float*>().swap(initialSeeds);
}

