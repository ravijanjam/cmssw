#ifndef RecoLocalCalo_EcalRecProducers_EcalRecHitWorkerSimple_hh
#define RecoLocalCalo_EcalRecProducers_EcalRecHitWorkerSimple_hh

/** \class EcalRecHitSimpleAlgo
  *  Simple algoritm to make rechits from uncalibrated rechits
  *
  *  $Id: EcalRecHitWorkerSimple.h,v 1.1 2008/12/10 01:52:41 ferriff Exp $
  *  $Date: 2008/12/10 01:52:41 $
  *  $Revision: 1.1 $
  *  \author Shahram Rahatlou, University of Rome & INFN, March 2006
  */

#include "RecoLocalCalo/EcalRecProducers/interface/EcalRecHitWorkerBaseClass.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalRecHitSimpleAlgo.h"

#include "FWCore/Framework/interface/ESHandle.h"

#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalTimeCalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalADCToGeVConstant.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"

#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbService.h"

class EcalRecHitWorkerSimple : public EcalRecHitWorkerBaseClass {
        public:
                EcalRecHitWorkerSimple(const edm::ParameterSet&);
                virtual ~EcalRecHitWorkerSimple() {};

                void set(const edm::EventSetup& es);
                bool run(const edm::Event& evt, const EcalUncalibratedRecHit& uncalibRH, EcalRecHitCollection & result);

        protected:

                edm::ESHandle<EcalIntercalibConstants> ical;
                edm::ESHandle<EcalTimeCalibConstants> itime;
                edm::ESHandle<EcalADCToGeVConstant> agc;
                edm::ESHandle<EcalChannelStatus> chStatus;
                std::vector<int> v_chstatus_;
                edm::ESHandle<EcalLaserDbService> laser;

                EcalRecHitSimpleAlgo * rechitMaker_;
};

#endif
