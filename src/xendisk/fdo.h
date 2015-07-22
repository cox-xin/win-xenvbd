/* Copyright (c) Citrix Systems Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided
 * that the following conditions are met:
 *
 * *   Redistributions of source code must retain the above
 *     copyright notice, this list of conditions and the
 *     following disclaimer.
 * *   Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the
 *     following disclaimer in the documentation and/or other
 *     materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _XENDISK_FDO_H
#define _XENDISK_FDO_H

#include <ntddk.h>
#include "types.h"

typedef struct _XENDISK_FDO XENDISK_FDO, *PXENDISK_FDO;

extern VOID
FdoAddPhysicalDeviceObject(
    IN  PXENDISK_FDO    Fdo,
    IN  PDEVICE_OBJECT  DeviceObject
    );

extern VOID
FdoRemovePhysicalDeviceObject(
    IN  PXENDISK_FDO    Fdo,
    IN  PDEVICE_OBJECT  DeviceObject
    );

extern VOID
FdoAcquireMutex(
    IN  PXENDISK_FDO     Fdo
    );

extern VOID
FdoReleaseMutex(
    IN  PXENDISK_FDO     Fdo
    );

extern PDEVICE_OBJECT
FdoGetPhysicalDeviceObject(
    IN  PXENDISK_FDO    Fdo
    );

extern NTSTATUS
FdoDispatch(
    IN  PXENDISK_FDO    Fdo,
    IN  PIRP            Irp
    );

extern NTSTATUS
FdoCreate(
    IN  PDEVICE_OBJECT  PhysicalDeviceObject
    );

extern VOID
FdoDestroy(
    IN  PXENDISK_FDO    Fdo
    );

#endif // _XENDISK_FDO_H
