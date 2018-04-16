/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ONLINE_SHIPTDCUNPACK_H
#define ONLINE_SHIPTDCUNPACK_H

#include "FairUnpack.h"

class TClonesArray;

/**
 * An example unpacker of MBS data.
 */
class ShipTdcUnpack : public FairUnpack
{
  public:
    /** Standard Constructor. Input - MBS parameters of the detector. */
    ShipTdcUnpack(Short_t type = 94,
                  Short_t subType = 9400,
                  Short_t procId = 10,
                  Short_t subCrate = 1,
                  Short_t control = 3);

    /** Destructor. */
    virtual ~ShipTdcUnpack();

    /** Initialization. Called once, before the event loop. */
    virtual Bool_t Init();
    
    /** Process an MBS sub-event. */
    virtual Bool_t DoUnpack(Int_t* data, Int_t size);
    
    /** Clear the output structures. */
    virtual void Reset();

    /** Method for controling the functionality. */
    inline Int_t GetNHitsTotal()
    {
        return fNHitsTotal;
    }

  protected:
    /** Register the output structures. */
    virtual void Register();

  private:
    TClonesArray* fRawData; /**< Array of output raw items. */
    Int_t fNHits;           /**< Number of raw items in current event. */
    Int_t fNHitsTotal;      /**< Total number of raw items. */

    ShipTdcUnpack(const ShipTdcUnpack&);
    ShipTdcUnpack& operator=(const ShipTdcUnpack&);
  public:
    // Class definition
    ClassDef(ShipTdcUnpack, 1)
};

#endif
