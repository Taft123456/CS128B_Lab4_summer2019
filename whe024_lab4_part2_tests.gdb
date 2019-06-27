# Test sequence from START: A0 && A1 => PORTC: 0x00
test "PINA: 0x03 => PORTC: 0x00, state: RESET"
set state = START
setPINA 0x03
continue 2
expectPORTC 0x00
checkResult

# Test sequence from INIT: A0, A1 => PORTC: 0x00
test "PINA: 0x01, 0x02 => PORTC: 0x00, state: RESET"
set state = INIT
setPINA 0x01
continue 2
setPINA 0x02
continue 2
expectPORTC 0x00
checkResult

# Test sequence from INIT: A1, A0 => PORTC: 0x00
test "PINA: 0x02, 0x01 => PORTC: 0x00, state: RESET"
set state = INIT
setPINA 0x02
continue 2
setPINA 0x01
continue 2
expectPORTC 0x00
checkResult

test “PORTC < 9 => PORTC: 0x09”
set exampleTick::PORTC = 0x09
set state = INCR
setPINA 0x01
continue 2
expectPORTC 0x09
expect state INCR
checkResult

test “PORTC > 0 => PORTC: 0x00”
set exampleTick::PORTC = 0x00
set state = DECR
setPINA 0x02
continue 2
expectPORTC 0x00
expect state DECR
checkResult