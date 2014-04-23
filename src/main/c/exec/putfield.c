/*
 *  XAM Xerxys Artificial Machine
 *  Copyright (C) 2005-2012 Christian Lins <christian@lins.me>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <xam.h>

/* Set field in object */
void do_PUTFIELD(struct VMTHREAD *thread)
{
    uint16_t index;
    dbgmsg("PUTFIELD");

    index = Get2ByteOperand(current_frame(thread));
}
