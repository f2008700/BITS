if {$argc != 1} {
		puts stderr "Error!! Invalid number of arguments"
		exit 1
		} else    {
	global ns x 
	set x [lindex $argv 0]
	}
	
if {$x>15||$x<0} {
	  puts stderr "Error!! node number is out of range!!"
	  exit 1
	  }

if {$x==0} {
	  puts stderr "Both source and destination is same, choose another node!!"
	  exit 1
	  }

set ns [new Simulator]

#
#Open the Trace files
set tracefile1 [open out.tr w]
set winfile [open WinFile. w]
$ns trace-all $tracefile1

#Open the NAM trace file
set namfile [open out.nam w]
$ns namtrace-all $namfile


#Define a 'finish' procedure
proc finish {} {
	global ns tracefile1 namfile
	$ns flush-trace
	close $tracefile1
	close $namfile
	exec nam out.nam &
	exit 0
}


set nbr 15
#nodes
for {set j 0} {$j<=$nbr} { incr j } {
set n($j) [$ns node]
}



Class Sender -superclass Agent/Message
Sender instproc send-next {next_hop dest seq} {

	$self instvar seq_ agent_addr_ dest_ dst_addr_
	global count ns
	set dest_ $dest
	set dst_addr_ $next_hop
	set seq_ $seq
	set time_ [$ns now]
	if { $time_ < 5 } {
	$self send "SRC: $agent_addr_ SEQ: $seq_ NEXT_HOP: $dst_addr_  DST: $dest_ type: data"
	global ns
}
}

Class Receiver -superclass Sender

for {set i 0} {$i<16} {incr i} {
	set seq_node($i) 0
	set arr_node($i) -1
}

for {set i 0} {$i<16} {incr i} {

	set udp($i) [new Agent/UDP]
	$ns attach-agent $n($i) $udp($i)
	set null($i) [new Agent/Null]
	$ns attach-agent $n($i) $null($i)
	set sndr($i) [new Sender]
	$ns attach-agent $n($i) $sndr($i)
	set rcvr($i) [new Receiver]
	$ns attach-agent $n($i) $rcvr($i)
}


Receiver instproc recv {msg} {
	
	$self instvar seq_ agent_addr_ dest_addr_ dest_
	global ns sndr seq_node 
	global ns sndr arr_node
	set sdr [lindex $msg 1]
	set seq [lindex $msg 3]
	set dst_addr_ [lindex $msg 5]
	set dest_ [lindex $msg 7]
	set pkt_type_ [lindex $msg 9]
	
	puts "seq_node= $seq_node($agent_addr_) and seq= $seq for $agent_addr_ "
	
	if {$arr_node($agent_addr_) == -1} {
	
	
	set seq_node($agent_addr_) $seq
	incr seq
	
	if {$agent_addr_ == 0} {

		if {$sdr != 1} { $ns at [expr [$ns now] + 0.2] "$sndr(1) send-next 1 1 $seq" }
		if {$sdr != 4} { $ns at [expr [$ns now] + 0.2] "$sndr(1) send-next 4 4 $seq" }
	}

	if {$agent_addr_ == 1} {

		if {$sdr != 0} { $ns at [expr [$ns now] + 0.2] "$sndr(1) send-next 0 0 $seq" }
		if {$sdr != 2} { $ns at [expr [$ns now] + 0.2] "$sndr(1) send-next 2 2 $seq" }
		if {$sdr != 5} { $ns at [expr [$ns now] + 0.2] "$sndr(1) send-next 5 5 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"	
	}
	
	if {$agent_addr_ == 2} {
		if {$sdr != 1} { $ns at [expr [$ns now] + 0.2] "$sndr(2) send-next 1 1 $seq" }
		if {$sdr != 2} { $ns at [expr [$ns now] + 0.2] "$sndr(2) send-next 3 3 $seq" }
		if {$sdr != 6} { $ns at [expr [$ns now] + 0.2] "$sndr(2) send-next 6 6 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}
		
	if {$agent_addr_ == 3} {
		if {$sdr != 2} { $ns at [expr [$ns now] + 0.2] "$sndr(3) send-next 2 2 $seq" }
		if {$sdr != 3} { $ns at [expr [$ns now] + 0.2] "$sndr(3) send-next 7 7 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 4} {
		if {$sdr != 0} { $ns at [expr [$ns now] + 0.2] "$sndr(4) send-next 0 0 $seq" }
		if {$sdr != 5} { $ns at [expr [$ns now] + 0.2] "$sndr(4) send-next 5 5 $seq" }
		if {$sdr != 8} { $ns at [expr [$ns now] + 0.2] "$sndr(4) send-next 8 8 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}
	
	if {$agent_addr_ == 5} {
		if {$sdr != 1} { $ns at [expr [$ns now] + 0.2] "$sndr(5) send-next 1 1 $seq" }
		if {$sdr != 4} { $ns at [expr [$ns now] + 0.2] "$sndr(5) send-next 4 4 $seq" }
		if {$sdr != 6} { $ns at [expr [$ns now] + 0.2] "$sndr(5) send-next 6 6 $seq" }
		if {$sdr != 9} { $ns at [expr [$ns now] + 0.2] "$sndr(5) send-next 9 9 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}
	
	if {$agent_addr_ == 6} {
		if {$sdr != 2} { $ns at [expr [$ns now] + 0.2] "$sndr(6) send-next 2 2 $seq" }
		if {$sdr != 5} { $ns at [expr [$ns now] + 0.2] "$sndr(6) send-next 5 5 $seq" }
		if {$sdr != 7} { $ns at [expr [$ns now] + 0.2] "$sndr(6) send-next 7 7 $seq" }
		if {$sdr != 10} { $ns at [expr [$ns now] + 0.2] "$sndr(6) send-next 10 10 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 7} {
		if {$sdr != 3} { $ns at [expr [$ns now] + 0.2] "$sndr(7) send-next 3 3 $seq" }
		if {$sdr != 6} { $ns at [expr [$ns now] + 0.2] "$sndr(7) send-next 6 6 $seq" }
		if {$sdr != 11} { $ns at [expr [$ns now] + 0.2] "$sndr(7) send-next 11 11 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}
	
	if {$agent_addr_ == 8} {
		if {$sdr != 4} { $ns at [expr [$ns now] + 0.2] "$sndr(8) send-next 4 4 $seq" }
		if {$sdr != 9} { $ns at [expr [$ns now] + 0.2] "$sndr(8) send-next 9 9 $seq" }
		if {$sdr != 12} { $ns at [expr [$ns now] + 0.2] "$sndr(8) send-next 12 12 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 9} {
		if {$sdr != 5} { $ns at [expr [$ns now] + 0.2] "$sndr(9) send-next 5 5 $seq" }
		if {$sdr != 8} { $ns at [expr [$ns now] + 0.2] "$sndr(9) send-next 8 8 $seq" }
		if {$sdr != 10} { $ns at [expr [$ns now] + 0.2] "$sndr(9) send-next 10 10 $seq" }
		if {$sdr != 13} { $ns at [expr [$ns now] + 0.2] "$sndr(9) send-next 13 13 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 10} {
		if {$sdr != 6} { $ns at [expr [$ns now] + 0.2] "$sndr(10) send-next 6 6 $seq" }
		if {$sdr != 11} { $ns at [expr [$ns now] + 0.2] "$sndr(10) send-next 11 11 $seq" }
		if {$sdr != 14} { $ns at [expr [$ns now] + 0.2] "$sndr(10) send-next 14 14 $seq" }
		if {$sdr != 9} { $ns at [expr [$ns now] + 0.2] "$sndr(10) send-next 9 9 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 11} {
		if {$sdr != 7} { $ns at [expr [$ns now] + 0.2] "$sndr(11) send-next 7 7 $seq" }
		if {$sdr != 10} { $ns at [expr [$ns now] + 0.2] "$sndr(11) send-next 10 10 $seq" }
		if {$sdr != 15} { $ns at [expr [$ns now] + 0.2] "$sndr(11) send-next 15 15 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 12} {
		if {$sdr != 8} { $ns at [expr [$ns now] + 0.2] "$sndr(12) send-next 8 8 $seq" }
		if {$sdr != 13} { $ns at [expr [$ns now] + 0.2] "$sndr(12) send-next 13 13 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 13} {
		if {$sdr != 12} { $ns at [expr [$ns now] + 0.2] "$sndr(13) send-next 12 12 $seq" }
		if {$sdr != 9} { $ns at [expr [$ns now] + 0.2] "$sndr(13) send-next 9 9 $seq" }
		if {$sdr != 14} { $ns at [expr [$ns now] + 0.2] "$sndr(13) send-next 14 14 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 14} {
		if {$sdr != 10} { $ns at [expr [$ns now] + 0.2] "$sndr(14) send-next 10 10 $seq" }
		if {$sdr != 15} { $ns at [expr [$ns now] + 0.2] "$sndr(14) send-next 15 15 $seq" }
		if {$sdr != 13} { $ns at [expr [$ns now] + 0.2] "$sndr(14) send-next 13 13 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}

	if {$agent_addr_ == 15} {
		if {$sdr != 11} { $ns at [expr [$ns now] + 0.2] "$sndr(15) send-next 11 11 $seq" }
		if {$sdr != 10} { $ns at [expr [$ns now] + 0.2] "$sndr(15) send-next 10 10 $seq" }
		if {$sdr != 14} { $ns at [expr [$ns now] + 0.2] "$sndr(15) send-next 14 14 $seq" }
		
		if {$arr_node($agent_addr_) == -1} { 
			set arr_node($agent_addr_) $sdr 	
		}
		#puts "setting it $arr_node($agent_addr_)"
	}
	
	}
	
	
	
}



#create duplex links
#Create link between the nodes

$ns duplex-link $n(0) $n(1) 1Mb 10ms DropTail
$ns duplex-link $n(0) $n(4) 1Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 1Mb 10ms DropTail
$ns duplex-link $n(1) $n(5) 1Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 1Mb 10ms DropTail
$ns duplex-link $n(2) $n(6) 1Mb 10ms DropTail
$ns duplex-link $n(3) $n(7) 1Mb 10ms DropTail

$ns duplex-link $n(4) $n(5) 1Mb 10ms DropTail
$ns duplex-link $n(4) $n(8) 1Mb 10ms DropTail
$ns duplex-link $n(5) $n(6) 1Mb 10ms DropTail
$ns duplex-link $n(5) $n(9) 1Mb 10ms DropTail
$ns duplex-link $n(6) $n(7) 1Mb 10ms DropTail
$ns duplex-link $n(6) $n(10) 1Mb 10ms DropTail
$ns duplex-link $n(7) $n(11) 1Mb 10ms DropTail

$ns duplex-link $n(8) $n(9) 1Mb 10ms DropTail
$ns duplex-link $n(8) $n(12) 1Mb 10ms DropTail
$ns duplex-link $n(9) $n(10) 1Mb 10ms DropTail
$ns duplex-link $n(9) $n(13) 1Mb 10ms DropTail
$ns duplex-link $n(10) $n(11) 1Mb 10ms DropTail
$ns duplex-link $n(10) $n(14) 1Mb 10ms DropTail
$ns duplex-link $n(11) $n(15) 1Mb 10ms DropTail

$ns duplex-link $n(12) $n(13) 1Mb 10ms DropTail
$ns duplex-link $n(13) $n(14) 1Mb 10ms DropTail
$ns duplex-link $n(14) $n(15) 1Mb 10ms DropTail


#Give node position (for NAM)
$ns duplex-link-op $n(0) $n(1) orient left
$ns duplex-link-op $n(1) $n(2) orient left
$ns duplex-link-op $n(2) $n(3) orient left
$ns duplex-link-op $n(0) $n(4) orient up
$ns duplex-link-op $n(1) $n(5) orient up
$ns duplex-link-op $n(2) $n(6) orient up
$ns duplex-link-op $n(3) $n(7) orient up

$ns duplex-link-op $n(4) $n(5) orient left
$ns duplex-link-op $n(5) $n(6) orient left
$ns duplex-link-op $n(6) $n(7) orient left
$ns duplex-link-op $n(4) $n(8) orient up
$ns duplex-link-op $n(5) $n(9) orient up
$ns duplex-link-op $n(6) $n(10) orient up
$ns duplex-link-op $n(7) $n(11) orient up

$ns duplex-link-op $n(8) $n(9) orient left
$ns duplex-link-op $n(9) $n(10) orient left
$ns duplex-link-op $n(10) $n(11) orient left
$ns duplex-link-op $n(8) $n(12) orient up
$ns duplex-link-op $n(9) $n(13) orient up
$ns duplex-link-op $n(10) $n(14) orient up
$ns duplex-link-op $n(11) $n(15) orient up

$ns duplex-link-op $n(12) $n(13) orient left
$ns duplex-link-op $n(13) $n(14) orient left
$ns duplex-link-op $n(14) $n(15) orient left



#connections- connect udp to null
$ns connect $udp(0) $null(1)
$ns connect $udp(1) $null(2)
$ns connect $udp(2) $null(3)
$ns connect $udp(4) $null(5)
$ns connect $udp(5) $null(6)
$ns connect $udp(6) $null(7)
$ns connect $udp(8) $null(9)
$ns connect $udp(9) $null(10)
$ns connect $udp(10) $null(11)
$ns connect $udp(12) $null(13)
$ns connect $udp(13) $null(14)
$ns connect $udp(14) $null(15)

$ns connect $udp(0) $null(4)
$ns connect $udp(4) $null(8)
$ns connect $udp(8) $null(12)
$ns connect $udp(1) $null(5)
$ns connect $udp(5) $null(9)
$ns connect $udp(9) $null(13)
$ns connect $udp(2) $null(6)
$ns connect $udp(6) $null(10)
$ns connect $udp(10) $null(14)
$ns connect $udp(3) $null(7)
$ns connect $udp(7) $null(11)
$ns connect $udp(11) $null(15)

$ns connect $udp(1) $null(0)
$ns connect $udp(2) $null(1)
$ns connect $udp(3) $null(2)
$ns connect $udp(5) $null(4)
$ns connect $udp(6) $null(5)
$ns connect $udp(7) $null(6)
$ns connect $udp(9) $null(8)
$ns connect $udp(10) $null(9)
$ns connect $udp(11) $null(10)
$ns connect $udp(13) $null(12)
$ns connect $udp(14) $null(13)
$ns connect $udp(15) $null(14)

$ns connect $udp(4) $null(0)
$ns connect $udp(8) $null(4)
$ns connect $udp(12) $null(12)
$ns connect $udp(5) $null(1)
$ns connect $udp(9) $null(5)
$ns connect $udp(13) $null(13)
$ns connect $udp(6) $null(2)
$ns connect $udp(10) $null(6)
$ns connect $udp(14) $null(10)
$ns connect $udp(7) $null(3)
$ns connect $udp(11) $null(7)
$ns connect $udp(15) $null(11)


#connecting senders to receivers
$ns connect $sndr(0) $rcvr(1)
$ns connect $sndr(1) $rcvr(2)
$ns connect $sndr(2) $rcvr(3)
$ns connect $sndr(4) $rcvr(5)
$ns connect $sndr(5) $rcvr(6)
$ns connect $sndr(6) $rcvr(7)
$ns connect $sndr(8) $rcvr(9)
$ns connect $sndr(9) $rcvr(10)
$ns connect $sndr(10) $rcvr(11)
$ns connect $sndr(12) $rcvr(13)
$ns connect $sndr(13) $rcvr(14)
$ns connect $sndr(14) $rcvr(15)

$ns connect $sndr(0) $rcvr(4)
$ns connect $sndr(4) $rcvr(8)
$ns connect $sndr(8) $rcvr(12)
$ns connect $sndr(1) $rcvr(5)
$ns connect $sndr(5) $rcvr(9)
$ns connect $sndr(9) $rcvr(13)
$ns connect $sndr(2) $rcvr(6)
$ns connect $sndr(6) $rcvr(10)
$ns connect $sndr(10) $rcvr(14)
$ns connect $sndr(3) $rcvr(7)
$ns connect $sndr(7) $rcvr(11)
$ns connect $sndr(11) $rcvr(15)

$ns connect $sndr(1) $rcvr(0)
$ns connect $sndr(2) $rcvr(1)
$ns connect $sndr(3) $rcvr(2)
$ns connect $sndr(5) $rcvr(4)
$ns connect $sndr(6) $rcvr(5)
$ns connect $sndr(7) $rcvr(6)
$ns connect $sndr(9) $rcvr(8)
$ns connect $sndr(10) $rcvr(9)
$ns connect $sndr(11) $rcvr(10)
$ns connect $sndr(13) $rcvr(12)
$ns connect $sndr(14) $rcvr(13)
$ns connect $sndr(15) $rcvr(14)

$ns connect $sndr(4) $rcvr(0)
$ns connect $sndr(8) $rcvr(4)
$ns connect $sndr(12) $rcvr(12)
$ns connect $sndr(5) $rcvr(1)
$ns connect $sndr(9) $rcvr(5)
$ns connect $sndr(13) $rcvr(13)
$ns connect $sndr(6) $rcvr(2)
$ns connect $sndr(10) $rcvr(6)
$ns connect $sndr(14) $rcvr(10)
$ns connect $sndr(7) $rcvr(3)
$ns connect $sndr(11) $rcvr(7)
$ns connect $sndr(15) $rcvr(11)


#Setup a TCP Connection-1
set tcp [new Agent/TCP]
$ns attach-agent $n($x) $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n(0) $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set packetSize_ 500


#Setup FTP over TCP Connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
	
	
proc printit {} {
global ns arr_node
global ns x
puts "routing table is as follows"
for {set i 1} {$i<=15} {incr i} {
puts " node=$i : $arr_node($i)"
}

if {$x != 0} {
puts "path followed is-"

puts "$x"
for {} {$arr_node($x)!=0} {set x $arr_node($x)} {
puts "$arr_node($x)"
}
puts "$arr_node($x)"
} 

}

	
$ns at 0.15 "$sndr(0) send-next 1 1 0"
$ns at 0.15 "$sndr(0) send-next 4 4 0"
$ns at 5.0 "$ftp start"
$ns at 30.0 "$ftp stop"
$ns at 35.0 printit




#Procedure for plotting window size.
proc plotWindow {tcpSource file} {
	global ns
	set time 0.1
	set now [$ns now]
	set cwnd [$tcpSource set cwnd_]
	puts $file "$now $cwnd"
	$ns at [expr $now+$time] "plotWindow $tcpSource $file"
}
$ns at 0.1 "plotWindow $tcp $winfile"

$ns at 40.0 "finish"

$ns run
