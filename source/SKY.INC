; ---------------------------------------------------------------------------
; - Stars - Sky Routines (sky.inc)                                          -
; - Copyright (C) 1998-2024 Alexandru Groza of Microprogramming TECHNIQUES  -
; - All rights reserved.                                                    -
; ---------------------------------------------------------------------------
; - License: GNU General Public License v3.0                                -
; ---------------------------------------------------------------------------

; routines:
;   + skyScan
;   + skyStarSequence
;   + skyStarNew
;   + skyStarDeflate
;   + skyStarInflate
;   + skyStarExtinct
;   + skyStarPulseDim
;   + skyStarPulseBright
;   + skyStarExplode
;
; data structures:
;   + starRoutineTable
; ---------------------------------------------------------------------------

; Randomly scans the sky for stars.
; Input:
;     none
; Output:
;     DL - star frame at random position
; Affects:
;     BX, DX
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyScan proc near

  xor bh,bh
  mov bl,kVGARowCount
  call random
  mov dh,bl

  xor bh,bh
  mov bl,kVGAColumnCount
  call random
  mov dl,bl

  call videoMoveCursor

  mov ah,08h
  xor bh,bh
  int 10h

  mov dl,al

  ret

skyScan endp

; Draws a star with a specific frame from the sequence.
; Input:
;     BL - frame number
; Output:
;     none
; Affects:
;     SI, AX, BX
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarSequence proc near

  xor bh,bh
  lea si,[kStars + bx]

  lodsw
  mov bl,ah
  call videoWriteChar

  mov bx,kStarSequenceSpeed
  call delay

  ret

skyStarSequence endp

; Draws a new single star randomly on the sky.
; Input:
;     none
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarNew proc near

  cmp byte ptr [dStarCount],kStarMaximumCount
  ja @@exit

  cmp dl,kStars + kStarExtinct
  jnz @@exit

  mov bl,kStarNew
  call skyStarSequence

  inc byte ptr [dStarCount]

@@exit:
  ret

skyStarNew endp

; Dims a shining star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarDeflate proc near

  cmp dl,kStars + kStarShine
  jnz @@exit

  mov bl,kStarNew
  call skyStarSequence

  dec byte ptr [dInflatedCount]

@@exit:
  ret

skyStarDeflate endp

; Shines a dim star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarInflate proc near

  cmp byte ptr [dInflatedCount],kInflatedMaximumCount
  ja @@exit

  cmp dl,kStars + kStarNew
  jnz @@exit

  mov bl,kStarShine
  call skyStarSequence

  inc byte ptr [dInflatedCount]

@@exit:
  ret

skyStarInflate endp

; Extincts an exploded star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarExtinct proc near

  cmp dl,kStars + kStarExploded
  jnz @@exit

  mov bl,kStarExtinct
  call skyStarSequence

  dec byte ptr [dStarCount]

@@exit:
  ret

skyStarExtinct endp

; Animates a dim shining star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarPulseDim proc near

  cmp dl,kStars + kStarNew
  jnz @@exit

  mov bl,kStarExtinct
  call skyStarSequence

  mov bl,kStarNew
  call skyStarSequence

@@exit:
  ret

skyStarPulseDim endp

; Animates a bright shining star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     BL
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarPulseBright proc near

  cmp dl,kStars + kStarNew
  jnz @@exit

  mov bl,kStarInflate
  call skyStarSequence

  mov bl,kStarNew
  call skyStarSequence

@@exit:
  ret

skyStarPulseBright endp

; Animates a dying of a star.
; Input:
;     DL - current star animation frame
; Output:
;     none
; Affects:
;     SI, DI, BX
; Preserves:
;     none
; ---------------------------------------------------------------------------
skyStarExplode proc near

  cmp dl,kStars + kStarNew
  jnz @@exit

  mov si,offset [kStars + kStarShine]
  mov di,kStarExplodeFrames

@@doSequence:
  lodsw
  mov bl,ah
  call videoWriteChar

  mov bx,kStarExplodeFrameSpeed
  call delay

  dec di
  jnz @@doSequence

@@exit:
  ret

skyStarExplode endp

; vector of pointers to invokable routines
; ---------------------------------------------------------------------------
starRoutineTable:
  DW skyStarNew
  DW skyStarDeflate
  DW skyStarInflate
  DW skyStarExtinct
  DW skyStarPulseDim
  DW skyStarPulseBright
  DW skyStarExplode
