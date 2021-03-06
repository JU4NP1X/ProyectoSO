/**
 * @file actor_jefe_epidemia.c
 * @author Jesús Pelay
 * @brief 
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "actores.h"
#include "definiciones.h"
#include <stdbool.h>
/** 
 * @brief Gestiona las estadísticas de los casos de covid para los hospitales
 *        y también a la gestión nacional  
 * 
 * @param datos_hospital datos del hospital cuyas estadísticas estamos llevando
 * 
 */

//extern Estadistica statHospital[NACTUALIZACIONES][NHOSPITALES];
//extern Hospital   Tabla_Hospitales[NHOSPITALES];
//extern UGC        gestor_central;

void* actor_director(void* datos_hospital) {
    Hospital* current_hosp = (Hospital *) datos_hospital;
    
    pthread_mutex_lock(&(current_hosp->estadisticasLock));
    
    statHospital[gestor_central.turno][current_hosp->id] = current_hosp->estadis_pacientes;
    current_hosp->estadis_pacientes.covid = 0;
    current_hosp->estadis_pacientes.dadosDeAlta = 0;
    current_hosp->estadis_pacientes.hospitalizados = 0;
    current_hosp->estadis_pacientes.monitoreados = 0;
    current_hosp->estadis_pacientes.muertos = 0;

    pthread_mutex_unlock(&(current_hosp->estadisticasLock));

    return NULL;
}
