// Clear existing database (Optional - uncomment to use)
// MATCH (n) DETACH DELETE n;

MERGE (n:Protocol {id: 'LTE'}) SET n += {id: 'LTE'};
MERGE (n:Protocol {id: '5G_NR'}) SET n += {id: '5G_NR'};
MERGE (n:Protocol {id: 'WiFi_6'}) SET n += {id: 'WiFi_6'};
MERGE (n:Protocol {id: 'NB-IoT'}) SET n += {id: 'NB-IoT'};
MERGE (n:Protocol {id: 'ZigBee'}) SET n += {id: 'ZigBee'};
MERGE (n:Module {id: 'Sync_Unit'}) SET n += {id: 'Sync_Unit'};
MERGE (n:Module {id: 'Demodulator'}) SET n += {id: 'Demodulator'};
MERGE (n:Module {id: 'Decoder'}) SET n += {id: 'Decoder'};
MERGE (n:Module {id: 'Scheduler'}) SET n += {id: 'Scheduler'};
MERGE (n:Module {id: 'DMA_Controller'}) SET n += {id: 'DMA_Controller'};
MERGE (n:Module {id: 'RF_FrontEnd'}) SET n += {id: 'RF_FrontEnd'};
MERGE (n:Module {id: 'FFT_Engine'}) SET n += {id: 'FFT_Engine'};
MERGE (n:Module {id: 'Scrambler'}) SET n += {id: 'Scrambler'};
MERGE (n:Module {id: 'Interleaver'}) SET n += {id: 'Interleaver'};
MERGE (n:Module {id: 'Rate_Matcher'}) SET n += {id: 'Rate_Matcher'};
MERGE (n:Module {id: 'CRC_Checker'}) SET n += {id: 'CRC_Checker'};
MERGE (n:Module {id: 'L1_Controller'}) SET n += {id: 'L1_Controller'};
MERGE (n:Module {id: 'MAC_Filter'}) SET n += {id: 'MAC_Filter'};
MERGE (n:Module {id: 'RRC_Manager'}) SET n += {id: 'RRC_Manager'};
MERGE (n:Module {id: 'Beam_Forming_Unit'}) SET n += {id: 'Beam_Forming_Unit'};
MERGE (n:Condition {id: 'Low_SNR'}) SET n += {id: 'Low_SNR'};
MERGE (n:Condition {id: 'High_Doppler'}) SET n += {id: 'High_Doppler'};
MERGE (n:Condition {id: 'Interference'}) SET n += {id: 'Interference'};
MERGE (n:Condition {id: 'Buffer_Overflow'}) SET n += {id: 'Buffer_Overflow'};
MERGE (n:Condition {id: 'Clock_Jitter'}) SET n += {id: 'Clock_Jitter'};
MERGE (n:Condition {id: 'Temperature_High'}) SET n += {id: 'Temperature_High'};
MERGE (n:Condition {id: 'Voltage_Drop'}) SET n += {id: 'Voltage_Drop'};
MERGE (n:Condition {id: 'Multi_Path_Fading'}) SET n += {id: 'Multi_Path_Fading'};
MERGE (n:Condition {id: 'Shadowing'}) SET n += {id: 'Shadowing'};
MERGE (n:Condition {id: 'Packet_Loss_Burst'}) SET n += {id: 'Packet_Loss_Burst'};
MERGE (n:Condition {id: 'Channel_Congestion'}) SET n += {id: 'Channel_Congestion'};
MERGE (n:Condition {id: 'Neighbor_Cell_Interference'}) SET n += {id: 'Neighbor_Cell_Interference'};
MERGE (n:Register {id: 'REG_0x3E8'}) SET n += {address: '0x3E8', id: 'REG_0x3E8'};
MERGE (n:Register {id: 'REG_0x3E9'}) SET n += {address: '0x3E9', id: 'REG_0x3E9'};
MERGE (n:Register {id: 'REG_0x3EA'}) SET n += {address: '0x3EA', id: 'REG_0x3EA'};
MERGE (n:Register {id: 'REG_0x3EB'}) SET n += {address: '0x3EB', id: 'REG_0x3EB'};
MERGE (n:Register {id: 'REG_0x3EC'}) SET n += {address: '0x3EC', id: 'REG_0x3EC'};
MERGE (n:Register {id: 'REG_0x3ED'}) SET n += {address: '0x3ED', id: 'REG_0x3ED'};
MERGE (n:Register {id: 'REG_0x3EE'}) SET n += {address: '0x3EE', id: 'REG_0x3EE'};
MERGE (n:Register {id: 'REG_0x3EF'}) SET n += {address: '0x3EF', id: 'REG_0x3EF'};
MERGE (n:Register {id: 'REG_0x3F0'}) SET n += {address: '0x3F0', id: 'REG_0x3F0'};
MERGE (n:Register {id: 'REG_0x3F1'}) SET n += {address: '0x3F1', id: 'REG_0x3F1'};
MERGE (n:Register {id: 'REG_0x3F2'}) SET n += {address: '0x3F2', id: 'REG_0x3F2'};
MERGE (n:Register {id: 'REG_0x3F3'}) SET n += {address: '0x3F3', id: 'REG_0x3F3'};
MERGE (n:Register {id: 'REG_0x3F4'}) SET n += {address: '0x3F4', id: 'REG_0x3F4'};
MERGE (n:Register {id: 'REG_0x3F5'}) SET n += {address: '0x3F5', id: 'REG_0x3F5'};
MERGE (n:Register {id: 'REG_0x3F6'}) SET n += {address: '0x3F6', id: 'REG_0x3F6'};
MERGE (n:Register {id: 'REG_0x3F7'}) SET n += {address: '0x3F7', id: 'REG_0x3F7'};
MERGE (n:Register {id: 'REG_0x3F8'}) SET n += {address: '0x3F8', id: 'REG_0x3F8'};
MERGE (n:Register {id: 'REG_0x3F9'}) SET n += {address: '0x3F9', id: 'REG_0x3F9'};
MERGE (n:Register {id: 'REG_0x3FA'}) SET n += {address: '0x3FA', id: 'REG_0x3FA'};
MERGE (n:Register {id: 'REG_0x3FB'}) SET n += {address: '0x3FB', id: 'REG_0x3FB'};
MERGE (n:Register {id: 'REG_0x3FC'}) SET n += {address: '0x3FC', id: 'REG_0x3FC'};
MERGE (n:Register {id: 'REG_0x3FD'}) SET n += {address: '0x3FD', id: 'REG_0x3FD'};
MERGE (n:Register {id: 'REG_0x3FE'}) SET n += {address: '0x3FE', id: 'REG_0x3FE'};
MERGE (n:Register {id: 'REG_0x3FF'}) SET n += {address: '0x3FF', id: 'REG_0x3FF'};
MERGE (n:Register {id: 'REG_0x400'}) SET n += {address: '0x400', id: 'REG_0x400'};
MERGE (n:Register {id: 'REG_0x401'}) SET n += {address: '0x401', id: 'REG_0x401'};
MERGE (n:Register {id: 'REG_0x402'}) SET n += {address: '0x402', id: 'REG_0x402'};
MERGE (n:Register {id: 'REG_0x403'}) SET n += {address: '0x403', id: 'REG_0x403'};
MERGE (n:Register {id: 'REG_0x404'}) SET n += {address: '0x404', id: 'REG_0x404'};
MERGE (n:Register {id: 'REG_0x405'}) SET n += {address: '0x405', id: 'REG_0x405'};
MERGE (n:Register {id: 'REG_0x406'}) SET n += {address: '0x406', id: 'REG_0x406'};
MERGE (n:Register {id: 'REG_0x407'}) SET n += {address: '0x407', id: 'REG_0x407'};
MERGE (n:Register {id: 'REG_0x408'}) SET n += {address: '0x408', id: 'REG_0x408'};
MERGE (n:Register {id: 'REG_0x409'}) SET n += {address: '0x409', id: 'REG_0x409'};
MERGE (n:Register {id: 'REG_0x40A'}) SET n += {address: '0x40A', id: 'REG_0x40A'};
MERGE (n:Register {id: 'REG_0x40B'}) SET n += {address: '0x40B', id: 'REG_0x40B'};
MERGE (n:Register {id: 'REG_0x40C'}) SET n += {address: '0x40C', id: 'REG_0x40C'};
MERGE (n:Register {id: 'REG_0x40D'}) SET n += {address: '0x40D', id: 'REG_0x40D'};
MERGE (n:Register {id: 'REG_0x40E'}) SET n += {address: '0x40E', id: 'REG_0x40E'};
MERGE (n:Register {id: 'REG_0x40F'}) SET n += {address: '0x40F', id: 'REG_0x40F'};
MERGE (n:Register {id: 'REG_0x410'}) SET n += {address: '0x410', id: 'REG_0x410'};
MERGE (n:Register {id: 'REG_0x411'}) SET n += {address: '0x411', id: 'REG_0x411'};
MERGE (n:Register {id: 'REG_0x412'}) SET n += {address: '0x412', id: 'REG_0x412'};
MERGE (n:Register {id: 'REG_0x413'}) SET n += {address: '0x413', id: 'REG_0x413'};
MERGE (n:Register {id: 'REG_0x414'}) SET n += {address: '0x414', id: 'REG_0x414'};
MERGE (n:Register {id: 'REG_0x415'}) SET n += {address: '0x415', id: 'REG_0x415'};
MERGE (n:Register {id: 'REG_0x416'}) SET n += {address: '0x416', id: 'REG_0x416'};
MERGE (n:Register {id: 'REG_0x417'}) SET n += {address: '0x417', id: 'REG_0x417'};
MERGE (n:Register {id: 'REG_0x418'}) SET n += {address: '0x418', id: 'REG_0x418'};
MERGE (n:Register {id: 'REG_0x419'}) SET n += {address: '0x419', id: 'REG_0x419'};
MERGE (n:Error {id: 'LTE_PSS_Miss'}) SET n += {layer: 'PHY', id: 'LTE_PSS_Miss'};
MERGE (n:Solution {id: 'LTE_Adjust_Sync_Threshold_55'}) SET n += {cost: 'Low', id: 'LTE_Adjust_Sync_Threshold_55'};
MERGE (n:Error {id: 'LTE_SSS_Detection_Fail'}) SET n += {layer: 'PHY', id: 'LTE_SSS_Detection_Fail'};
MERGE (n:Solution {id: 'LTE_Reset_Sync_State_76'}) SET n += {cost: 'Low', id: 'LTE_Reset_Sync_State_76'};
MERGE (n:Error {id: 'LTE_CFO_Drift'}) SET n += {layer: 'PHY', id: 'LTE_CFO_Drift'};
MERGE (n:Solution {id: 'LTE_Widen_Search_Window_93'}) SET n += {cost: 'Low', id: 'LTE_Widen_Search_Window_93'};
MERGE (n:Error {id: 'LTE_Timing_Offset'}) SET n += {layer: 'PHY', id: 'LTE_Timing_Offset'};
MERGE (n:Solution {id: 'LTE_Widen_Search_Window_51'}) SET n += {cost: 'Low', id: 'LTE_Widen_Search_Window_51'};
MERGE (n:Error {id: 'LTE_Frame_Sync_Lost'}) SET n += {layer: 'PHY', id: 'LTE_Frame_Sync_Lost'};
MERGE (n:Solution {id: 'LTE_Reset_Sync_State_73'}) SET n += {cost: 'Low', id: 'LTE_Reset_Sync_State_73'};
MERGE (n:Error {id: 'LTE_Symbol_Boundary_Error'}) SET n += {layer: 'PHY', id: 'LTE_Symbol_Boundary_Error'};
MERGE (n:Solution {id: 'LTE_Switch_Beam_87'}) SET n += {cost: 'Low', id: 'LTE_Switch_Beam_87'};
MERGE (n:Error {id: '5G_NR_PSS_Miss'}) SET n += {layer: 'PHY', id: '5G_NR_PSS_Miss'};
MERGE (n:Solution {id: '5G_NR_Widen_Search_Window_76'}) SET n += {cost: 'Low', id: '5G_NR_Widen_Search_Window_76'};
MERGE (n:Error {id: '5G_NR_SSS_Detection_Fail'}) SET n += {layer: 'PHY', id: '5G_NR_SSS_Detection_Fail'};
MERGE (n:Solution {id: '5G_NR_Adjust_Sync_Threshold_76'}) SET n += {cost: 'Low', id: '5G_NR_Adjust_Sync_Threshold_76'};
MERGE (n:Error {id: '5G_NR_CFO_Drift'}) SET n += {layer: 'PHY', id: '5G_NR_CFO_Drift'};
MERGE (n:Solution {id: '5G_NR_Adjust_Sync_Threshold_56'}) SET n += {cost: 'Low', id: '5G_NR_Adjust_Sync_Threshold_56'};
MERGE (n:Error {id: '5G_NR_Timing_Offset'}) SET n += {layer: 'PHY', id: '5G_NR_Timing_Offset'};
MERGE (n:Solution {id: '5G_NR_Reset_Sync_State_66'}) SET n += {cost: 'Low', id: '5G_NR_Reset_Sync_State_66'};
MERGE (n:Error {id: '5G_NR_Frame_Sync_Lost'}) SET n += {layer: 'PHY', id: '5G_NR_Frame_Sync_Lost'};
MERGE (n:Solution {id: '5G_NR_Reset_Sync_State_18'}) SET n += {cost: 'Low', id: '5G_NR_Reset_Sync_State_18'};
MERGE (n:Error {id: '5G_NR_Symbol_Boundary_Error'}) SET n += {layer: 'PHY', id: '5G_NR_Symbol_Boundary_Error'};
MERGE (n:Solution {id: '5G_NR_Switch_Beam_50'}) SET n += {cost: 'Low', id: '5G_NR_Switch_Beam_50'};
MERGE (n:Error {id: 'WiFi_6_PSS_Miss'}) SET n += {layer: 'PHY', id: 'WiFi_6_PSS_Miss'};
MERGE (n:Solution {id: 'WiFi_6_Widen_Search_Window_76'}) SET n += {cost: 'Low', id: 'WiFi_6_Widen_Search_Window_76'};
MERGE (n:Error {id: 'WiFi_6_SSS_Detection_Fail'}) SET n += {layer: 'PHY', id: 'WiFi_6_SSS_Detection_Fail'};
MERGE (n:Solution {id: 'WiFi_6_Adjust_Sync_Threshold_26'}) SET n += {cost: 'Low', id: 'WiFi_6_Adjust_Sync_Threshold_26'};
MERGE (n:Error {id: 'WiFi_6_CFO_Drift'}) SET n += {layer: 'PHY', id: 'WiFi_6_CFO_Drift'};
MERGE (n:Solution {id: 'WiFi_6_Reset_Sync_State_12'}) SET n += {cost: 'Low', id: 'WiFi_6_Reset_Sync_State_12'};
MERGE (n:Error {id: 'WiFi_6_Timing_Offset'}) SET n += {layer: 'PHY', id: 'WiFi_6_Timing_Offset'};
MERGE (n:Solution {id: 'WiFi_6_Widen_Search_Window_13'}) SET n += {cost: 'Low', id: 'WiFi_6_Widen_Search_Window_13'};
MERGE (n:Error {id: 'WiFi_6_Frame_Sync_Lost'}) SET n += {layer: 'PHY', id: 'WiFi_6_Frame_Sync_Lost'};
MERGE (n:Solution {id: 'WiFi_6_Widen_Search_Window_88'}) SET n += {cost: 'Low', id: 'WiFi_6_Widen_Search_Window_88'};
MERGE (n:Error {id: 'WiFi_6_Symbol_Boundary_Error'}) SET n += {layer: 'PHY', id: 'WiFi_6_Symbol_Boundary_Error'};
MERGE (n:Solution {id: 'WiFi_6_Adjust_Sync_Threshold_57'}) SET n += {cost: 'Low', id: 'WiFi_6_Adjust_Sync_Threshold_57'};
MERGE (n:Error {id: 'NB-IoT_PSS_Miss'}) SET n += {layer: 'PHY', id: 'NB-IoT_PSS_Miss'};
MERGE (n:Solution {id: 'NB-IoT_Switch_Beam_43'}) SET n += {cost: 'Low', id: 'NB-IoT_Switch_Beam_43'};
MERGE (n:Error {id: 'NB-IoT_SSS_Detection_Fail'}) SET n += {layer: 'PHY', id: 'NB-IoT_SSS_Detection_Fail'};
MERGE (n:Solution {id: 'NB-IoT_Reset_Sync_State_8'}) SET n += {cost: 'Low', id: 'NB-IoT_Reset_Sync_State_8'};
MERGE (n:Error {id: 'NB-IoT_CFO_Drift'}) SET n += {layer: 'PHY', id: 'NB-IoT_CFO_Drift'};
MERGE (n:Solution {id: 'NB-IoT_Widen_Search_Window_44'}) SET n += {cost: 'Low', id: 'NB-IoT_Widen_Search_Window_44'};
MERGE (n:Error {id: 'NB-IoT_Timing_Offset'}) SET n += {layer: 'PHY', id: 'NB-IoT_Timing_Offset'};
MERGE (n:Solution {id: 'NB-IoT_Switch_Beam_35'}) SET n += {cost: 'Low', id: 'NB-IoT_Switch_Beam_35'};
MERGE (n:Error {id: 'NB-IoT_Frame_Sync_Lost'}) SET n += {layer: 'PHY', id: 'NB-IoT_Frame_Sync_Lost'};
MERGE (n:Solution {id: 'NB-IoT_Reset_Sync_State_40'}) SET n += {cost: 'Low', id: 'NB-IoT_Reset_Sync_State_40'};
MERGE (n:Error {id: 'NB-IoT_Symbol_Boundary_Error'}) SET n += {layer: 'PHY', id: 'NB-IoT_Symbol_Boundary_Error'};
MERGE (n:Solution {id: 'NB-IoT_Enable_Freq_Tracking_3'}) SET n += {cost: 'Low', id: 'NB-IoT_Enable_Freq_Tracking_3'};
MERGE (n:Error {id: 'ZigBee_PSS_Miss'}) SET n += {layer: 'PHY', id: 'ZigBee_PSS_Miss'};
MERGE (n:Solution {id: 'ZigBee_Switch_Beam_25'}) SET n += {cost: 'Low', id: 'ZigBee_Switch_Beam_25'};
MERGE (n:Error {id: 'ZigBee_SSS_Detection_Fail'}) SET n += {layer: 'PHY', id: 'ZigBee_SSS_Detection_Fail'};
MERGE (n:Solution {id: 'ZigBee_Enable_Freq_Tracking_3'}) SET n += {cost: 'Low', id: 'ZigBee_Enable_Freq_Tracking_3'};
MERGE (n:Error {id: 'ZigBee_CFO_Drift'}) SET n += {layer: 'PHY', id: 'ZigBee_CFO_Drift'};
MERGE (n:Solution {id: 'ZigBee_Enable_Freq_Tracking_84'}) SET n += {cost: 'Low', id: 'ZigBee_Enable_Freq_Tracking_84'};
MERGE (n:Error {id: 'ZigBee_Timing_Offset'}) SET n += {layer: 'PHY', id: 'ZigBee_Timing_Offset'};
MERGE (n:Solution {id: 'ZigBee_Widen_Search_Window_39'}) SET n += {cost: 'Low', id: 'ZigBee_Widen_Search_Window_39'};
MERGE (n:Error {id: 'ZigBee_Frame_Sync_Lost'}) SET n += {layer: 'PHY', id: 'ZigBee_Frame_Sync_Lost'};
MERGE (n:Solution {id: 'ZigBee_Reset_Sync_State_100'}) SET n += {cost: 'Low', id: 'ZigBee_Reset_Sync_State_100'};
MERGE (n:Error {id: 'ZigBee_Symbol_Boundary_Error'}) SET n += {layer: 'PHY', id: 'ZigBee_Symbol_Boundary_Error'};
MERGE (n:Solution {id: 'ZigBee_Adjust_Sync_Threshold_70'}) SET n += {cost: 'Low', id: 'ZigBee_Adjust_Sync_Threshold_70'};
MERGE (n:Error {id: 'LTE_Constellation_Mismatch'}) SET n += {layer: 'MAC', id: 'LTE_Constellation_Mismatch'};
MERGE (n:Solution {id: 'LTE_Request_Retransmission_8'}) SET n += {cost: 'Medium', id: 'LTE_Request_Retransmission_8'};
MERGE (n:Error {id: 'LTE_EVM_High'}) SET n += {layer: 'MAC', id: 'LTE_EVM_High'};
MERGE (n:Solution {id: 'LTE_Request_Retransmission_99'}) SET n += {cost: 'Medium', id: 'LTE_Request_Retransmission_99'};
MERGE (n:Error {id: 'LTE_LDPC_Decode_Fail'}) SET n += {layer: 'MAC', id: 'LTE_LDPC_Decode_Fail'};
MERGE (n:Solution {id: 'LTE_Enable_Diversity_72'}) SET n += {cost: 'Medium', id: 'LTE_Enable_Diversity_72'};
MERGE (n:Error {id: 'LTE_CRC_Error'}) SET n += {layer: 'MAC', id: 'LTE_CRC_Error'};
MERGE (n:Solution {id: 'LTE_Enable_Diversity_36'}) SET n += {cost: 'Medium', id: 'LTE_Enable_Diversity_36'};
MERGE (n:Error {id: 'LTE_Polar_Code_Fail'}) SET n += {layer: 'MAC', id: 'LTE_Polar_Code_Fail'};
MERGE (n:Solution {id: 'LTE_Lower_MCS_72'}) SET n += {cost: 'Medium', id: 'LTE_Lower_MCS_72'};
MERGE (n:Error {id: 'LTE_QAM_Demap_Error'}) SET n += {layer: 'MAC', id: 'LTE_QAM_Demap_Error'};
MERGE (n:Solution {id: 'LTE_Lower_MCS_50'}) SET n += {cost: 'Medium', id: 'LTE_Lower_MCS_50'};
MERGE (n:Error {id: '5G_NR_Constellation_Mismatch'}) SET n += {layer: 'MAC', id: '5G_NR_Constellation_Mismatch'};
MERGE (n:Solution {id: '5G_NR_Increase_Power_50'}) SET n += {cost: 'Medium', id: '5G_NR_Increase_Power_50'};
MERGE (n:Error {id: '5G_NR_EVM_High'}) SET n += {layer: 'MAC', id: '5G_NR_EVM_High'};
MERGE (n:Solution {id: '5G_NR_Increase_Power_59'}) SET n += {cost: 'Medium', id: '5G_NR_Increase_Power_59'};
MERGE (n:Error {id: '5G_NR_LDPC_Decode_Fail'}) SET n += {layer: 'MAC', id: '5G_NR_LDPC_Decode_Fail'};
MERGE (n:Solution {id: '5G_NR_Request_Retransmission_11'}) SET n += {cost: 'Medium', id: '5G_NR_Request_Retransmission_11'};
MERGE (n:Error {id: '5G_NR_CRC_Error'}) SET n += {layer: 'MAC', id: '5G_NR_CRC_Error'};
MERGE (n:Solution {id: '5G_NR_Lower_MCS_20'}) SET n += {cost: 'Medium', id: '5G_NR_Lower_MCS_20'};
MERGE (n:Error {id: '5G_NR_Polar_Code_Fail'}) SET n += {layer: 'MAC', id: '5G_NR_Polar_Code_Fail'};
MERGE (n:Solution {id: '5G_NR_Request_Retransmission_87'}) SET n += {cost: 'Medium', id: '5G_NR_Request_Retransmission_87'};
MERGE (n:Error {id: '5G_NR_QAM_Demap_Error'}) SET n += {layer: 'MAC', id: '5G_NR_QAM_Demap_Error'};
MERGE (n:Solution {id: '5G_NR_Soft_Reset_Rx_65'}) SET n += {cost: 'Medium', id: '5G_NR_Soft_Reset_Rx_65'};
MERGE (n:Error {id: 'WiFi_6_Constellation_Mismatch'}) SET n += {layer: 'MAC', id: 'WiFi_6_Constellation_Mismatch'};
MERGE (n:Solution {id: 'WiFi_6_Increase_Power_7'}) SET n += {cost: 'Medium', id: 'WiFi_6_Increase_Power_7'};
MERGE (n:Error {id: 'WiFi_6_EVM_High'}) SET n += {layer: 'MAC', id: 'WiFi_6_EVM_High'};
MERGE (n:Solution {id: 'WiFi_6_Request_Retransmission_12'}) SET n += {cost: 'Medium', id: 'WiFi_6_Request_Retransmission_12'};
MERGE (n:Error {id: 'WiFi_6_LDPC_Decode_Fail'}) SET n += {layer: 'MAC', id: 'WiFi_6_LDPC_Decode_Fail'};
MERGE (n:Solution {id: 'WiFi_6_Enable_Diversity_47'}) SET n += {cost: 'Medium', id: 'WiFi_6_Enable_Diversity_47'};
MERGE (n:Error {id: 'WiFi_6_CRC_Error'}) SET n += {layer: 'MAC', id: 'WiFi_6_CRC_Error'};
MERGE (n:Solution {id: 'WiFi_6_Increase_Power_63'}) SET n += {cost: 'Medium', id: 'WiFi_6_Increase_Power_63'};
MERGE (n:Error {id: 'WiFi_6_Polar_Code_Fail'}) SET n += {layer: 'MAC', id: 'WiFi_6_Polar_Code_Fail'};
MERGE (n:Solution {id: 'WiFi_6_Request_Retransmission_55'}) SET n += {cost: 'Medium', id: 'WiFi_6_Request_Retransmission_55'};
MERGE (n:Error {id: 'WiFi_6_QAM_Demap_Error'}) SET n += {layer: 'MAC', id: 'WiFi_6_QAM_Demap_Error'};
MERGE (n:Solution {id: 'WiFi_6_Enable_Diversity_13'}) SET n += {cost: 'Medium', id: 'WiFi_6_Enable_Diversity_13'};
MERGE (n:Error {id: 'NB-IoT_Constellation_Mismatch'}) SET n += {layer: 'MAC', id: 'NB-IoT_Constellation_Mismatch'};
MERGE (n:Solution {id: 'NB-IoT_Request_Retransmission_15'}) SET n += {cost: 'Medium', id: 'NB-IoT_Request_Retransmission_15'};
MERGE (n:Error {id: 'NB-IoT_EVM_High'}) SET n += {layer: 'MAC', id: 'NB-IoT_EVM_High'};
MERGE (n:Solution {id: 'NB-IoT_Enable_Diversity_93'}) SET n += {cost: 'Medium', id: 'NB-IoT_Enable_Diversity_93'};
MERGE (n:Error {id: 'NB-IoT_LDPC_Decode_Fail'}) SET n += {layer: 'MAC', id: 'NB-IoT_LDPC_Decode_Fail'};
MERGE (n:Solution {id: 'NB-IoT_Enable_Diversity_51'}) SET n += {cost: 'Medium', id: 'NB-IoT_Enable_Diversity_51'};
MERGE (n:Error {id: 'NB-IoT_CRC_Error'}) SET n += {layer: 'MAC', id: 'NB-IoT_CRC_Error'};
MERGE (n:Solution {id: 'NB-IoT_Request_Retransmission_16'}) SET n += {cost: 'Medium', id: 'NB-IoT_Request_Retransmission_16'};
MERGE (n:Error {id: 'NB-IoT_Polar_Code_Fail'}) SET n += {layer: 'MAC', id: 'NB-IoT_Polar_Code_Fail'};
MERGE (n:Solution {id: 'NB-IoT_Increase_Power_24'}) SET n += {cost: 'Medium', id: 'NB-IoT_Increase_Power_24'};
MERGE (n:Error {id: 'NB-IoT_QAM_Demap_Error'}) SET n += {layer: 'MAC', id: 'NB-IoT_QAM_Demap_Error'};
MERGE (n:Solution {id: 'NB-IoT_Request_Retransmission_21'}) SET n += {cost: 'Medium', id: 'NB-IoT_Request_Retransmission_21'};
MERGE (n:Error {id: 'ZigBee_Constellation_Mismatch'}) SET n += {layer: 'MAC', id: 'ZigBee_Constellation_Mismatch'};
MERGE (n:Solution {id: 'ZigBee_Increase_Power_12'}) SET n += {cost: 'Medium', id: 'ZigBee_Increase_Power_12'};
MERGE (n:Error {id: 'ZigBee_EVM_High'}) SET n += {layer: 'MAC', id: 'ZigBee_EVM_High'};
MERGE (n:Solution {id: 'ZigBee_Request_Retransmission_62'}) SET n += {cost: 'Medium', id: 'ZigBee_Request_Retransmission_62'};
MERGE (n:Error {id: 'ZigBee_LDPC_Decode_Fail'}) SET n += {layer: 'MAC', id: 'ZigBee_LDPC_Decode_Fail'};
MERGE (n:Solution {id: 'ZigBee_Soft_Reset_Rx_74'}) SET n += {cost: 'Medium', id: 'ZigBee_Soft_Reset_Rx_74'};
MERGE (n:Error {id: 'ZigBee_CRC_Error'}) SET n += {layer: 'MAC', id: 'ZigBee_CRC_Error'};
MERGE (n:Solution {id: 'ZigBee_Enable_Diversity_43'}) SET n += {cost: 'Medium', id: 'ZigBee_Enable_Diversity_43'};
MERGE (n:Error {id: 'ZigBee_Polar_Code_Fail'}) SET n += {layer: 'MAC', id: 'ZigBee_Polar_Code_Fail'};
MERGE (n:Solution {id: 'ZigBee_Request_Retransmission_22'}) SET n += {cost: 'Medium', id: 'ZigBee_Request_Retransmission_22'};
MERGE (n:Error {id: 'ZigBee_QAM_Demap_Error'}) SET n += {layer: 'MAC', id: 'ZigBee_QAM_Demap_Error'};
MERGE (n:Solution {id: 'ZigBee_Enable_Diversity_88'}) SET n += {cost: 'Medium', id: 'ZigBee_Enable_Diversity_88'};
MERGE (n:Error {id: 'Context_Switch_Timeout'}) SET n += {layer: 'SYS', id: 'Context_Switch_Timeout'};
MERGE (n:Solution {id: 'SOL_Force_Unlock_84'}) SET n += {cost: 'High', id: 'SOL_Force_Unlock_84'};
MERGE (n:Entity {id: 'ModeSwitch'}) SET n += {id: 'ModeSwitch'};
MERGE (n:Error {id: 'Shadow_Reg_Update_Fail'}) SET n += {layer: 'SYS', id: 'Shadow_Reg_Update_Fail'};
MERGE (n:Solution {id: 'SOL_Clear_Shadow_Buffer_94'}) SET n += {cost: 'High', id: 'SOL_Clear_Shadow_Buffer_94'};
MERGE (n:Error {id: 'DMA_Bus_Hang'}) SET n += {layer: 'SYS', id: 'DMA_Bus_Hang'};
MERGE (n:Solution {id: 'SOL_Flush_Pipeline_34'}) SET n += {cost: 'High', id: 'SOL_Flush_Pipeline_34'};
MERGE (n:Error {id: 'Watchdog_Reset'}) SET n += {layer: 'SYS', id: 'Watchdog_Reset'};
MERGE (n:Solution {id: 'SOL_Force_Unlock_68'}) SET n += {cost: 'High', id: 'SOL_Force_Unlock_68'};
MERGE (n:Error {id: 'Instruction_Fetch_Error'}) SET n += {layer: 'SYS', id: 'Instruction_Fetch_Error'};
MERGE (n:Solution {id: 'SOL_Flush_Pipeline_48'}) SET n += {cost: 'High', id: 'SOL_Flush_Pipeline_48'};
MERGE (n:Error {id: 'Memory_Parity_Error'}) SET n += {layer: 'SYS', id: 'Memory_Parity_Error'};
MERGE (n:Solution {id: 'SOL_Clear_Shadow_Buffer_17'}) SET n += {cost: 'High', id: 'SOL_Clear_Shadow_Buffer_17'};
MERGE (n:Error {id: 'AXI_Bus_Lockup'}) SET n += {layer: 'SYS', id: 'AXI_Bus_Lockup'};
MERGE (n:Solution {id: 'SOL_Clear_Shadow_Buffer_56'}) SET n += {cost: 'High', id: 'SOL_Clear_Shadow_Buffer_56'};
MERGE (n:Error {id: 'FIFO_Underrun'}) SET n += {layer: 'SYS', id: 'FIFO_Underrun'};
MERGE (n:Solution {id: 'SOL_Reset_CGRA_Tile_40'}) SET n += {cost: 'High', id: 'SOL_Reset_CGRA_Tile_40'};
MERGE (n:LogSignature {id: 'LOG_MSG_0000'}) SET n += {pattern: 'Error code 0 detected', id: 'LOG_MSG_0000'};
MERGE (n:LogSignature {id: 'LOG_MSG_0001'}) SET n += {pattern: 'Error code 1 detected', id: 'LOG_MSG_0001'};
MERGE (n:LogSignature {id: 'LOG_MSG_0002'}) SET n += {pattern: 'Error code 2 detected', id: 'LOG_MSG_0002'};
MERGE (n:LogSignature {id: 'LOG_MSG_0003'}) SET n += {pattern: 'Error code 3 detected', id: 'LOG_MSG_0003'};
MERGE (n:LogSignature {id: 'LOG_MSG_0004'}) SET n += {pattern: 'Error code 4 detected', id: 'LOG_MSG_0004'};
MERGE (n:LogSignature {id: 'LOG_MSG_0005'}) SET n += {pattern: 'Error code 5 detected', id: 'LOG_MSG_0005'};
MERGE (n:LogSignature {id: 'LOG_MSG_0006'}) SET n += {pattern: 'Error code 6 detected', id: 'LOG_MSG_0006'};
MERGE (n:LogSignature {id: 'LOG_MSG_0007'}) SET n += {pattern: 'Error code 7 detected', id: 'LOG_MSG_0007'};
MERGE (n:LogSignature {id: 'LOG_MSG_0008'}) SET n += {pattern: 'Error code 8 detected', id: 'LOG_MSG_0008'};
MERGE (n:LogSignature {id: 'LOG_MSG_0009'}) SET n += {pattern: 'Error code 9 detected', id: 'LOG_MSG_0009'};
MERGE (n:LogSignature {id: 'LOG_MSG_0010'}) SET n += {pattern: 'Error code 10 detected', id: 'LOG_MSG_0010'};
MERGE (n:LogSignature {id: 'LOG_MSG_0011'}) SET n += {pattern: 'Error code 11 detected', id: 'LOG_MSG_0011'};
MERGE (n:LogSignature {id: 'LOG_MSG_0012'}) SET n += {pattern: 'Error code 12 detected', id: 'LOG_MSG_0012'};
MERGE (n:LogSignature {id: 'LOG_MSG_0013'}) SET n += {pattern: 'Error code 13 detected', id: 'LOG_MSG_0013'};
MERGE (n:LogSignature {id: 'LOG_MSG_0014'}) SET n += {pattern: 'Error code 14 detected', id: 'LOG_MSG_0014'};
MERGE (n:LogSignature {id: 'LOG_MSG_0015'}) SET n += {pattern: 'Error code 15 detected', id: 'LOG_MSG_0015'};
MERGE (n:LogSignature {id: 'LOG_MSG_0016'}) SET n += {pattern: 'Error code 16 detected', id: 'LOG_MSG_0016'};
MERGE (n:LogSignature {id: 'LOG_MSG_0017'}) SET n += {pattern: 'Error code 17 detected', id: 'LOG_MSG_0017'};
MERGE (n:LogSignature {id: 'LOG_MSG_0018'}) SET n += {pattern: 'Error code 18 detected', id: 'LOG_MSG_0018'};
MERGE (n:LogSignature {id: 'LOG_MSG_0019'}) SET n += {pattern: 'Error code 19 detected', id: 'LOG_MSG_0019'};
MERGE (n:LogSignature {id: 'LOG_MSG_0020'}) SET n += {pattern: 'Error code 20 detected', id: 'LOG_MSG_0020'};
MERGE (n:LogSignature {id: 'LOG_MSG_0021'}) SET n += {pattern: 'Error code 21 detected', id: 'LOG_MSG_0021'};
MERGE (n:LogSignature {id: 'LOG_MSG_0022'}) SET n += {pattern: 'Error code 22 detected', id: 'LOG_MSG_0022'};
MERGE (n:LogSignature {id: 'LOG_MSG_0023'}) SET n += {pattern: 'Error code 23 detected', id: 'LOG_MSG_0023'};
MERGE (n:LogSignature {id: 'LOG_MSG_0024'}) SET n += {pattern: 'Error code 24 detected', id: 'LOG_MSG_0024'};
MERGE (n:LogSignature {id: 'LOG_MSG_0025'}) SET n += {pattern: 'Error code 25 detected', id: 'LOG_MSG_0025'};
MERGE (n:LogSignature {id: 'LOG_MSG_0026'}) SET n += {pattern: 'Error code 26 detected', id: 'LOG_MSG_0026'};
MERGE (n:LogSignature {id: 'LOG_MSG_0027'}) SET n += {pattern: 'Error code 27 detected', id: 'LOG_MSG_0027'};
MERGE (n:LogSignature {id: 'LOG_MSG_0028'}) SET n += {pattern: 'Error code 28 detected', id: 'LOG_MSG_0028'};
MERGE (n:LogSignature {id: 'LOG_MSG_0029'}) SET n += {pattern: 'Error code 29 detected', id: 'LOG_MSG_0029'};
MERGE (n:LogSignature {id: 'LOG_MSG_0030'}) SET n += {pattern: 'Error code 30 detected', id: 'LOG_MSG_0030'};
MERGE (n:LogSignature {id: 'LOG_MSG_0031'}) SET n += {pattern: 'Error code 31 detected', id: 'LOG_MSG_0031'};
MERGE (n:LogSignature {id: 'LOG_MSG_0032'}) SET n += {pattern: 'Error code 32 detected', id: 'LOG_MSG_0032'};
MERGE (n:LogSignature {id: 'LOG_MSG_0033'}) SET n += {pattern: 'Error code 33 detected', id: 'LOG_MSG_0033'};
MERGE (n:LogSignature {id: 'LOG_MSG_0034'}) SET n += {pattern: 'Error code 34 detected', id: 'LOG_MSG_0034'};
MERGE (n:LogSignature {id: 'LOG_MSG_0035'}) SET n += {pattern: 'Error code 35 detected', id: 'LOG_MSG_0035'};
MERGE (n:LogSignature {id: 'LOG_MSG_0036'}) SET n += {pattern: 'Error code 36 detected', id: 'LOG_MSG_0036'};
MERGE (n:LogSignature {id: 'LOG_MSG_0037'}) SET n += {pattern: 'Error code 37 detected', id: 'LOG_MSG_0037'};
MERGE (n:LogSignature {id: 'LOG_MSG_0038'}) SET n += {pattern: 'Error code 38 detected', id: 'LOG_MSG_0038'};
MERGE (n:LogSignature {id: 'LOG_MSG_0039'}) SET n += {pattern: 'Error code 39 detected', id: 'LOG_MSG_0039'};
MERGE (n:LogSignature {id: 'LOG_MSG_0040'}) SET n += {pattern: 'Error code 40 detected', id: 'LOG_MSG_0040'};
MERGE (n:LogSignature {id: 'LOG_MSG_0041'}) SET n += {pattern: 'Error code 41 detected', id: 'LOG_MSG_0041'};
MERGE (n:LogSignature {id: 'LOG_MSG_0042'}) SET n += {pattern: 'Error code 42 detected', id: 'LOG_MSG_0042'};
MERGE (n:LogSignature {id: 'LOG_MSG_0043'}) SET n += {pattern: 'Error code 43 detected', id: 'LOG_MSG_0043'};
MERGE (n:LogSignature {id: 'LOG_MSG_0044'}) SET n += {pattern: 'Error code 44 detected', id: 'LOG_MSG_0044'};
MERGE (n:LogSignature {id: 'LOG_MSG_0045'}) SET n += {pattern: 'Error code 45 detected', id: 'LOG_MSG_0045'};
MERGE (n:LogSignature {id: 'LOG_MSG_0046'}) SET n += {pattern: 'Error code 46 detected', id: 'LOG_MSG_0046'};
MERGE (n:LogSignature {id: 'LOG_MSG_0047'}) SET n += {pattern: 'Error code 47 detected', id: 'LOG_MSG_0047'};
MERGE (n:LogSignature {id: 'LOG_MSG_0048'}) SET n += {pattern: 'Error code 48 detected', id: 'LOG_MSG_0048'};
MERGE (n:LogSignature {id: 'LOG_MSG_0049'}) SET n += {pattern: 'Error code 49 detected', id: 'LOG_MSG_0049'};
MERGE (n:LogSignature {id: 'LOG_MSG_0050'}) SET n += {pattern: 'Error code 50 detected', id: 'LOG_MSG_0050'};
MERGE (n:LogSignature {id: 'LOG_MSG_0051'}) SET n += {pattern: 'Error code 51 detected', id: 'LOG_MSG_0051'};
MERGE (n:LogSignature {id: 'LOG_MSG_0052'}) SET n += {pattern: 'Error code 52 detected', id: 'LOG_MSG_0052'};
MERGE (n:LogSignature {id: 'LOG_MSG_0053'}) SET n += {pattern: 'Error code 53 detected', id: 'LOG_MSG_0053'};
MERGE (n:LogSignature {id: 'LOG_MSG_0054'}) SET n += {pattern: 'Error code 54 detected', id: 'LOG_MSG_0054'};
MERGE (n:LogSignature {id: 'LOG_MSG_0055'}) SET n += {pattern: 'Error code 55 detected', id: 'LOG_MSG_0055'};
MERGE (n:LogSignature {id: 'LOG_MSG_0056'}) SET n += {pattern: 'Error code 56 detected', id: 'LOG_MSG_0056'};
MERGE (n:LogSignature {id: 'LOG_MSG_0057'}) SET n += {pattern: 'Error code 57 detected', id: 'LOG_MSG_0057'};
MERGE (n:LogSignature {id: 'LOG_MSG_0058'}) SET n += {pattern: 'Error code 58 detected', id: 'LOG_MSG_0058'};
MERGE (n:LogSignature {id: 'LOG_MSG_0059'}) SET n += {pattern: 'Error code 59 detected', id: 'LOG_MSG_0059'};
MERGE (n:LogSignature {id: 'LOG_MSG_0060'}) SET n += {pattern: 'Error code 60 detected', id: 'LOG_MSG_0060'};
MERGE (n:LogSignature {id: 'LOG_MSG_0061'}) SET n += {pattern: 'Error code 61 detected', id: 'LOG_MSG_0061'};
MERGE (n:LogSignature {id: 'LOG_MSG_0062'}) SET n += {pattern: 'Error code 62 detected', id: 'LOG_MSG_0062'};
MERGE (n:LogSignature {id: 'LOG_MSG_0063'}) SET n += {pattern: 'Error code 63 detected', id: 'LOG_MSG_0063'};
MERGE (n:LogSignature {id: 'LOG_MSG_0064'}) SET n += {pattern: 'Error code 64 detected', id: 'LOG_MSG_0064'};
MERGE (n:LogSignature {id: 'LOG_MSG_0065'}) SET n += {pattern: 'Error code 65 detected', id: 'LOG_MSG_0065'};
MERGE (n:LogSignature {id: 'LOG_MSG_0066'}) SET n += {pattern: 'Error code 66 detected', id: 'LOG_MSG_0066'};
MERGE (n:LogSignature {id: 'LOG_MSG_0067'}) SET n += {pattern: 'Error code 67 detected', id: 'LOG_MSG_0067'};
MERGE (n:LogSignature {id: 'LOG_MSG_0068'}) SET n += {pattern: 'Error code 68 detected', id: 'LOG_MSG_0068'};
MERGE (n:LogSignature {id: 'LOG_MSG_0069'}) SET n += {pattern: 'Error code 69 detected', id: 'LOG_MSG_0069'};
MERGE (n:LogSignature {id: 'LOG_MSG_0070'}) SET n += {pattern: 'Error code 70 detected', id: 'LOG_MSG_0070'};
MERGE (n:LogSignature {id: 'LOG_MSG_0071'}) SET n += {pattern: 'Error code 71 detected', id: 'LOG_MSG_0071'};
MERGE (n:LogSignature {id: 'LOG_MSG_0072'}) SET n += {pattern: 'Error code 72 detected', id: 'LOG_MSG_0072'};
MERGE (n:LogSignature {id: 'LOG_MSG_0073'}) SET n += {pattern: 'Error code 73 detected', id: 'LOG_MSG_0073'};
MERGE (n:LogSignature {id: 'LOG_MSG_0074'}) SET n += {pattern: 'Error code 74 detected', id: 'LOG_MSG_0074'};
MERGE (n:LogSignature {id: 'LOG_MSG_0075'}) SET n += {pattern: 'Error code 75 detected', id: 'LOG_MSG_0075'};
MERGE (n:LogSignature {id: 'LOG_MSG_0076'}) SET n += {pattern: 'Error code 76 detected', id: 'LOG_MSG_0076'};
MERGE (n:LogSignature {id: 'LOG_MSG_0077'}) SET n += {pattern: 'Error code 77 detected', id: 'LOG_MSG_0077'};
MERGE (n:LogSignature {id: 'LOG_MSG_0078'}) SET n += {pattern: 'Error code 78 detected', id: 'LOG_MSG_0078'};
MERGE (n:LogSignature {id: 'LOG_MSG_0079'}) SET n += {pattern: 'Error code 79 detected', id: 'LOG_MSG_0079'};
MERGE (n:LogSignature {id: 'LOG_MSG_0080'}) SET n += {pattern: 'Error code 80 detected', id: 'LOG_MSG_0080'};
MERGE (n:LogSignature {id: 'LOG_MSG_0081'}) SET n += {pattern: 'Error code 81 detected', id: 'LOG_MSG_0081'};
MERGE (n:LogSignature {id: 'LOG_MSG_0082'}) SET n += {pattern: 'Error code 82 detected', id: 'LOG_MSG_0082'};
MERGE (n:LogSignature {id: 'LOG_MSG_0083'}) SET n += {pattern: 'Error code 83 detected', id: 'LOG_MSG_0083'};
MERGE (n:LogSignature {id: 'LOG_MSG_0084'}) SET n += {pattern: 'Error code 84 detected', id: 'LOG_MSG_0084'};
MERGE (n:LogSignature {id: 'LOG_MSG_0085'}) SET n += {pattern: 'Error code 85 detected', id: 'LOG_MSG_0085'};
MERGE (n:LogSignature {id: 'LOG_MSG_0086'}) SET n += {pattern: 'Error code 86 detected', id: 'LOG_MSG_0086'};
MERGE (n:LogSignature {id: 'LOG_MSG_0087'}) SET n += {pattern: 'Error code 87 detected', id: 'LOG_MSG_0087'};
MERGE (n:LogSignature {id: 'LOG_MSG_0088'}) SET n += {pattern: 'Error code 88 detected', id: 'LOG_MSG_0088'};
MERGE (n:LogSignature {id: 'LOG_MSG_0089'}) SET n += {pattern: 'Error code 89 detected', id: 'LOG_MSG_0089'};
MERGE (n:LogSignature {id: 'LOG_MSG_0090'}) SET n += {pattern: 'Error code 90 detected', id: 'LOG_MSG_0090'};
MERGE (n:LogSignature {id: 'LOG_MSG_0091'}) SET n += {pattern: 'Error code 91 detected', id: 'LOG_MSG_0091'};
MERGE (n:LogSignature {id: 'LOG_MSG_0092'}) SET n += {pattern: 'Error code 92 detected', id: 'LOG_MSG_0092'};
MERGE (n:LogSignature {id: 'LOG_MSG_0093'}) SET n += {pattern: 'Error code 93 detected', id: 'LOG_MSG_0093'};
MERGE (n:LogSignature {id: 'LOG_MSG_0094'}) SET n += {pattern: 'Error code 94 detected', id: 'LOG_MSG_0094'};
MERGE (n:LogSignature {id: 'LOG_MSG_0095'}) SET n += {pattern: 'Error code 95 detected', id: 'LOG_MSG_0095'};
MERGE (n:LogSignature {id: 'LOG_MSG_0096'}) SET n += {pattern: 'Error code 96 detected', id: 'LOG_MSG_0096'};
MERGE (n:LogSignature {id: 'LOG_MSG_0097'}) SET n += {pattern: 'Error code 97 detected', id: 'LOG_MSG_0097'};
MERGE (n:LogSignature {id: 'LOG_MSG_0098'}) SET n += {pattern: 'Error code 98 detected', id: 'LOG_MSG_0098'};
MERGE (n:LogSignature {id: 'LOG_MSG_0099'}) SET n += {pattern: 'Error code 99 detected', id: 'LOG_MSG_0099'};
MERGE (n:LogSignature {id: 'LOG_MSG_0100'}) SET n += {pattern: 'Error code 100 detected', id: 'LOG_MSG_0100'};
MERGE (n:LogSignature {id: 'LOG_MSG_0101'}) SET n += {pattern: 'Error code 101 detected', id: 'LOG_MSG_0101'};
MERGE (n:LogSignature {id: 'LOG_MSG_0102'}) SET n += {pattern: 'Error code 102 detected', id: 'LOG_MSG_0102'};
MERGE (n:LogSignature {id: 'LOG_MSG_0103'}) SET n += {pattern: 'Error code 103 detected', id: 'LOG_MSG_0103'};
MERGE (n:LogSignature {id: 'LOG_MSG_0104'}) SET n += {pattern: 'Error code 104 detected', id: 'LOG_MSG_0104'};
MERGE (n:LogSignature {id: 'LOG_MSG_0105'}) SET n += {pattern: 'Error code 105 detected', id: 'LOG_MSG_0105'};
MERGE (n:LogSignature {id: 'LOG_MSG_0106'}) SET n += {pattern: 'Error code 106 detected', id: 'LOG_MSG_0106'};
MERGE (n:LogSignature {id: 'LOG_MSG_0107'}) SET n += {pattern: 'Error code 107 detected', id: 'LOG_MSG_0107'};
MERGE (n:LogSignature {id: 'LOG_MSG_0108'}) SET n += {pattern: 'Error code 108 detected', id: 'LOG_MSG_0108'};
MERGE (n:LogSignature {id: 'LOG_MSG_0109'}) SET n += {pattern: 'Error code 109 detected', id: 'LOG_MSG_0109'};
MERGE (n:LogSignature {id: 'LOG_MSG_0110'}) SET n += {pattern: 'Error code 110 detected', id: 'LOG_MSG_0110'};
MERGE (n:LogSignature {id: 'LOG_MSG_0111'}) SET n += {pattern: 'Error code 111 detected', id: 'LOG_MSG_0111'};
MERGE (n:LogSignature {id: 'LOG_MSG_0112'}) SET n += {pattern: 'Error code 112 detected', id: 'LOG_MSG_0112'};
MERGE (n:LogSignature {id: 'LOG_MSG_0113'}) SET n += {pattern: 'Error code 113 detected', id: 'LOG_MSG_0113'};
MERGE (n:LogSignature {id: 'LOG_MSG_0114'}) SET n += {pattern: 'Error code 114 detected', id: 'LOG_MSG_0114'};
MERGE (n:LogSignature {id: 'LOG_MSG_0115'}) SET n += {pattern: 'Error code 115 detected', id: 'LOG_MSG_0115'};
MERGE (n:LogSignature {id: 'LOG_MSG_0116'}) SET n += {pattern: 'Error code 116 detected', id: 'LOG_MSG_0116'};
MERGE (n:LogSignature {id: 'LOG_MSG_0117'}) SET n += {pattern: 'Error code 117 detected', id: 'LOG_MSG_0117'};
MERGE (n:LogSignature {id: 'LOG_MSG_0118'}) SET n += {pattern: 'Error code 118 detected', id: 'LOG_MSG_0118'};
MERGE (n:LogSignature {id: 'LOG_MSG_0119'}) SET n += {pattern: 'Error code 119 detected', id: 'LOG_MSG_0119'};
MERGE (n:LogSignature {id: 'LOG_MSG_0120'}) SET n += {pattern: 'Error code 120 detected', id: 'LOG_MSG_0120'};
MERGE (n:LogSignature {id: 'LOG_MSG_0121'}) SET n += {pattern: 'Error code 121 detected', id: 'LOG_MSG_0121'};
MERGE (n:LogSignature {id: 'LOG_MSG_0122'}) SET n += {pattern: 'Error code 122 detected', id: 'LOG_MSG_0122'};
MERGE (n:LogSignature {id: 'LOG_MSG_0123'}) SET n += {pattern: 'Error code 123 detected', id: 'LOG_MSG_0123'};
MERGE (n:LogSignature {id: 'LOG_MSG_0124'}) SET n += {pattern: 'Error code 124 detected', id: 'LOG_MSG_0124'};
MERGE (n:LogSignature {id: 'LOG_MSG_0125'}) SET n += {pattern: 'Error code 125 detected', id: 'LOG_MSG_0125'};
MERGE (n:LogSignature {id: 'LOG_MSG_0126'}) SET n += {pattern: 'Error code 126 detected', id: 'LOG_MSG_0126'};
MERGE (n:LogSignature {id: 'LOG_MSG_0127'}) SET n += {pattern: 'Error code 127 detected', id: 'LOG_MSG_0127'};
MERGE (n:LogSignature {id: 'LOG_MSG_0128'}) SET n += {pattern: 'Error code 128 detected', id: 'LOG_MSG_0128'};
MERGE (n:LogSignature {id: 'LOG_MSG_0129'}) SET n += {pattern: 'Error code 129 detected', id: 'LOG_MSG_0129'};
MERGE (n:LogSignature {id: 'LOG_MSG_0130'}) SET n += {pattern: 'Error code 130 detected', id: 'LOG_MSG_0130'};
MERGE (n:LogSignature {id: 'LOG_MSG_0131'}) SET n += {pattern: 'Error code 131 detected', id: 'LOG_MSG_0131'};
MERGE (n:LogSignature {id: 'LOG_MSG_0132'}) SET n += {pattern: 'Error code 132 detected', id: 'LOG_MSG_0132'};
MERGE (n:LogSignature {id: 'LOG_MSG_0133'}) SET n += {pattern: 'Error code 133 detected', id: 'LOG_MSG_0133'};
MERGE (n:LogSignature {id: 'LOG_MSG_0134'}) SET n += {pattern: 'Error code 134 detected', id: 'LOG_MSG_0134'};
MERGE (n:LogSignature {id: 'LOG_MSG_0135'}) SET n += {pattern: 'Error code 135 detected', id: 'LOG_MSG_0135'};
MERGE (n:LogSignature {id: 'LOG_MSG_0136'}) SET n += {pattern: 'Error code 136 detected', id: 'LOG_MSG_0136'};
MERGE (n:LogSignature {id: 'LOG_MSG_0137'}) SET n += {pattern: 'Error code 137 detected', id: 'LOG_MSG_0137'};
MERGE (n:LogSignature {id: 'LOG_MSG_0138'}) SET n += {pattern: 'Error code 138 detected', id: 'LOG_MSG_0138'};
MERGE (n:LogSignature {id: 'LOG_MSG_0139'}) SET n += {pattern: 'Error code 139 detected', id: 'LOG_MSG_0139'};
MERGE (n:LogSignature {id: 'LOG_MSG_0140'}) SET n += {pattern: 'Error code 140 detected', id: 'LOG_MSG_0140'};
MERGE (n:LogSignature {id: 'LOG_MSG_0141'}) SET n += {pattern: 'Error code 141 detected', id: 'LOG_MSG_0141'};
MERGE (n:LogSignature {id: 'LOG_MSG_0142'}) SET n += {pattern: 'Error code 142 detected', id: 'LOG_MSG_0142'};
MERGE (n:LogSignature {id: 'LOG_MSG_0143'}) SET n += {pattern: 'Error code 143 detected', id: 'LOG_MSG_0143'};
MERGE (n:LogSignature {id: 'LOG_MSG_0144'}) SET n += {pattern: 'Error code 144 detected', id: 'LOG_MSG_0144'};
MERGE (n:LogSignature {id: 'LOG_MSG_0145'}) SET n += {pattern: 'Error code 145 detected', id: 'LOG_MSG_0145'};
MERGE (n:LogSignature {id: 'LOG_MSG_0146'}) SET n += {pattern: 'Error code 146 detected', id: 'LOG_MSG_0146'};
MERGE (n:LogSignature {id: 'LOG_MSG_0147'}) SET n += {pattern: 'Error code 147 detected', id: 'LOG_MSG_0147'};
MERGE (n:LogSignature {id: 'LOG_MSG_0148'}) SET n += {pattern: 'Error code 148 detected', id: 'LOG_MSG_0148'};
MERGE (n:LogSignature {id: 'LOG_MSG_0149'}) SET n += {pattern: 'Error code 149 detected', id: 'LOG_MSG_0149'};
MERGE (n:LogSignature {id: 'LOG_MSG_0150'}) SET n += {pattern: 'Error code 150 detected', id: 'LOG_MSG_0150'};
MERGE (n:LogSignature {id: 'LOG_MSG_0151'}) SET n += {pattern: 'Error code 151 detected', id: 'LOG_MSG_0151'};
MERGE (n:LogSignature {id: 'LOG_MSG_0152'}) SET n += {pattern: 'Error code 152 detected', id: 'LOG_MSG_0152'};
MERGE (n:LogSignature {id: 'LOG_MSG_0153'}) SET n += {pattern: 'Error code 153 detected', id: 'LOG_MSG_0153'};
MERGE (n:LogSignature {id: 'LOG_MSG_0154'}) SET n += {pattern: 'Error code 154 detected', id: 'LOG_MSG_0154'};
MERGE (n:LogSignature {id: 'LOG_MSG_0155'}) SET n += {pattern: 'Error code 155 detected', id: 'LOG_MSG_0155'};
MERGE (n:LogSignature {id: 'LOG_MSG_0156'}) SET n += {pattern: 'Error code 156 detected', id: 'LOG_MSG_0156'};
MERGE (n:LogSignature {id: 'LOG_MSG_0157'}) SET n += {pattern: 'Error code 157 detected', id: 'LOG_MSG_0157'};
MERGE (n:LogSignature {id: 'LOG_MSG_0158'}) SET n += {pattern: 'Error code 158 detected', id: 'LOG_MSG_0158'};
MERGE (n:LogSignature {id: 'LOG_MSG_0159'}) SET n += {pattern: 'Error code 159 detected', id: 'LOG_MSG_0159'};
MERGE (n:LogSignature {id: 'LOG_MSG_0160'}) SET n += {pattern: 'Error code 160 detected', id: 'LOG_MSG_0160'};
MERGE (n:LogSignature {id: 'LOG_MSG_0161'}) SET n += {pattern: 'Error code 161 detected', id: 'LOG_MSG_0161'};
MERGE (n:LogSignature {id: 'LOG_MSG_0162'}) SET n += {pattern: 'Error code 162 detected', id: 'LOG_MSG_0162'};
MERGE (n:LogSignature {id: 'LOG_MSG_0163'}) SET n += {pattern: 'Error code 163 detected', id: 'LOG_MSG_0163'};
MERGE (n:LogSignature {id: 'LOG_MSG_0164'}) SET n += {pattern: 'Error code 164 detected', id: 'LOG_MSG_0164'};
MERGE (n:LogSignature {id: 'LOG_MSG_0165'}) SET n += {pattern: 'Error code 165 detected', id: 'LOG_MSG_0165'};
MERGE (n:LogSignature {id: 'LOG_MSG_0166'}) SET n += {pattern: 'Error code 166 detected', id: 'LOG_MSG_0166'};
MERGE (n:LogSignature {id: 'LOG_MSG_0167'}) SET n += {pattern: 'Error code 167 detected', id: 'LOG_MSG_0167'};
MERGE (n:LogSignature {id: 'LOG_MSG_0168'}) SET n += {pattern: 'Error code 168 detected', id: 'LOG_MSG_0168'};
MERGE (n:LogSignature {id: 'LOG_MSG_0169'}) SET n += {pattern: 'Error code 169 detected', id: 'LOG_MSG_0169'};
MERGE (n:LogSignature {id: 'LOG_MSG_0170'}) SET n += {pattern: 'Error code 170 detected', id: 'LOG_MSG_0170'};
MERGE (n:LogSignature {id: 'LOG_MSG_0171'}) SET n += {pattern: 'Error code 171 detected', id: 'LOG_MSG_0171'};
MERGE (n:LogSignature {id: 'LOG_MSG_0172'}) SET n += {pattern: 'Error code 172 detected', id: 'LOG_MSG_0172'};
MERGE (n:LogSignature {id: 'LOG_MSG_0173'}) SET n += {pattern: 'Error code 173 detected', id: 'LOG_MSG_0173'};
MERGE (n:LogSignature {id: 'LOG_MSG_0174'}) SET n += {pattern: 'Error code 174 detected', id: 'LOG_MSG_0174'};
MERGE (n:LogSignature {id: 'LOG_MSG_0175'}) SET n += {pattern: 'Error code 175 detected', id: 'LOG_MSG_0175'};
MERGE (n:LogSignature {id: 'LOG_MSG_0176'}) SET n += {pattern: 'Error code 176 detected', id: 'LOG_MSG_0176'};
MERGE (n:LogSignature {id: 'LOG_MSG_0177'}) SET n += {pattern: 'Error code 177 detected', id: 'LOG_MSG_0177'};
MERGE (n:LogSignature {id: 'LOG_MSG_0178'}) SET n += {pattern: 'Error code 178 detected', id: 'LOG_MSG_0178'};
MERGE (n:LogSignature {id: 'LOG_MSG_0179'}) SET n += {pattern: 'Error code 179 detected', id: 'LOG_MSG_0179'};
MERGE (n:LogSignature {id: 'LOG_MSG_0180'}) SET n += {pattern: 'Error code 180 detected', id: 'LOG_MSG_0180'};
MERGE (n:LogSignature {id: 'LOG_MSG_0181'}) SET n += {pattern: 'Error code 181 detected', id: 'LOG_MSG_0181'};
MERGE (n:LogSignature {id: 'LOG_MSG_0182'}) SET n += {pattern: 'Error code 182 detected', id: 'LOG_MSG_0182'};
MERGE (n:LogSignature {id: 'LOG_MSG_0183'}) SET n += {pattern: 'Error code 183 detected', id: 'LOG_MSG_0183'};
MERGE (n:LogSignature {id: 'LOG_MSG_0184'}) SET n += {pattern: 'Error code 184 detected', id: 'LOG_MSG_0184'};
MERGE (n:LogSignature {id: 'LOG_MSG_0185'}) SET n += {pattern: 'Error code 185 detected', id: 'LOG_MSG_0185'};
MERGE (n:LogSignature {id: 'LOG_MSG_0186'}) SET n += {pattern: 'Error code 186 detected', id: 'LOG_MSG_0186'};
MERGE (n:LogSignature {id: 'LOG_MSG_0187'}) SET n += {pattern: 'Error code 187 detected', id: 'LOG_MSG_0187'};
MERGE (n:LogSignature {id: 'LOG_MSG_0188'}) SET n += {pattern: 'Error code 188 detected', id: 'LOG_MSG_0188'};
MERGE (n:LogSignature {id: 'LOG_MSG_0189'}) SET n += {pattern: 'Error code 189 detected', id: 'LOG_MSG_0189'};
MERGE (n:LogSignature {id: 'LOG_MSG_0190'}) SET n += {pattern: 'Error code 190 detected', id: 'LOG_MSG_0190'};
MERGE (n:LogSignature {id: 'LOG_MSG_0191'}) SET n += {pattern: 'Error code 191 detected', id: 'LOG_MSG_0191'};
MERGE (n:LogSignature {id: 'LOG_MSG_0192'}) SET n += {pattern: 'Error code 192 detected', id: 'LOG_MSG_0192'};
MERGE (n:LogSignature {id: 'LOG_MSG_0193'}) SET n += {pattern: 'Error code 193 detected', id: 'LOG_MSG_0193'};
MERGE (n:LogSignature {id: 'LOG_MSG_0194'}) SET n += {pattern: 'Error code 194 detected', id: 'LOG_MSG_0194'};
MERGE (n:LogSignature {id: 'LOG_MSG_0195'}) SET n += {pattern: 'Error code 195 detected', id: 'LOG_MSG_0195'};
MERGE (n:LogSignature {id: 'LOG_MSG_0196'}) SET n += {pattern: 'Error code 196 detected', id: 'LOG_MSG_0196'};
MERGE (n:LogSignature {id: 'LOG_MSG_0197'}) SET n += {pattern: 'Error code 197 detected', id: 'LOG_MSG_0197'};
MERGE (n:LogSignature {id: 'LOG_MSG_0198'}) SET n += {pattern: 'Error code 198 detected', id: 'LOG_MSG_0198'};
MERGE (n:LogSignature {id: 'LOG_MSG_0199'}) SET n += {pattern: 'Error code 199 detected', id: 'LOG_MSG_0199'};
MERGE (n:Parameter {id: 'SNR_Threshold'}) SET n += {id: 'SNR_Threshold'};
MERGE (n:Parameter {id: 'Retry_Limit'}) SET n += {id: 'Retry_Limit'};
MERGE (n:Parameter {id: 'Beam_Index'}) SET n += {id: 'Beam_Index'};
MERGE (n:Parameter {id: 'Subcarrier_Spacing'}) SET n += {id: 'Subcarrier_Spacing'};
MERGE (n:Parameter {id: 'Coding_Rate'}) SET n += {id: 'Coding_Rate'};
MERGE (n:Parameter {id: 'Modulation_Order'}) SET n += {id: 'Modulation_Order'};

MATCH (a {id: '5G_NR'}), (b {id: 'REG_0x405'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_Frame_Sync_Lost'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_PSS_Miss'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_Timing_Offset'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: '5G_NR_Symbol_Boundary_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_Timing_Offset'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_Frame_Sync_Lost'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'WiFi_6_Symbol_Boundary_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_PSS_Miss'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'NB-IoT_Symbol_Boundary_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_SSS_Detection_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_Timing_Offset'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_Frame_Sync_Lost'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Sync_Unit'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_Constellation_Mismatch'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_LDPC_Decode_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_CRC_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_Polar_Code_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'LTE_QAM_Demap_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_LDPC_Decode_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: '5G_NR_QAM_Demap_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_EVM_High'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_LDPC_Decode_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_Polar_Code_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'WiFi_6_QAM_Demap_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_Constellation_Mismatch'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_LDPC_Decode_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_Polar_Code_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'NB-IoT_QAM_Demap_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_LDPC_Decode_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_CRC_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:DETECTS]->(b);
MATCH (a {id: 'Demodulator'}), (b {id: 'ZigBee_SSS_Detection_Fail'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'Watchdog_Reset'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'Memory_Parity_Error'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'AXI_Bus_Lockup'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Scheduler'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:MONITORS]->(b);
MATCH (a {id: 'Rate_Matcher'}), (b {id: 'LOG_MSG_0038'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Rate_Matcher'}), (b {id: 'LOG_MSG_0058'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'RRC_Manager'}), (b {id: 'Modulation_Order'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Low_SNR'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: '5G_NR_PSS_Miss'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: '5G_NR_Symbol_Boundary_Error'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'WiFi_6_EVM_High'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'High_Doppler'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Interference'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Interference'}), (b {id: 'NB-IoT_PSS_Miss'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Interference'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Interference'}), (b {id: 'NB-IoT_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: 'LOG_MSG_0021'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: 'ZigBee_Frame_Sync_Lost'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Buffer_Overflow'}), (b {id: '5G_NR_Increase_Power_50'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Clock_Jitter'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Clock_Jitter'}), (b {id: 'WiFi_6_Symbol_Boundary_Error'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Clock_Jitter'}), (b {id: 'ZigBee_SSS_Detection_Fail'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Clock_Jitter'}), (b {id: 'LOG_MSG_0154'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Temperature_High'}), (b {id: 'ZigBee_Timing_Offset'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Multi_Path_Fading'}), (b {id: 'WiFi_6_Timing_Offset'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Multi_Path_Fading'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Multi_Path_Fading'}), (b {id: 'Channel_Congestion'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Shadowing'}), (b {id: 'LTE_Frame_Sync_Lost'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Shadowing'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Shadowing'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Shadowing'}), (b {id: 'ZigBee_Frame_Sync_Lost'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Packet_Loss_Burst'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Packet_Loss_Burst'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Packet_Loss_Burst'}), (b {id: 'NB-IoT_Symbol_Boundary_Error'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Channel_Congestion'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Channel_Congestion'}), (b {id: 'WiFi_6_Frame_Sync_Lost'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Channel_Congestion'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Channel_Congestion'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Neighbor_Cell_Interference'}), (b {id: '5G_NR_Timing_Offset'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Neighbor_Cell_Interference'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Neighbor_Cell_Interference'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:CAUSES]->(b);
MATCH (a {id: 'Neighbor_Cell_Interference'}), (b {id: 'NB-IoT_Request_Retransmission_15'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Neighbor_Cell_Interference'}), (b {id: 'LOG_MSG_0136'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3E8'}), (b {id: 'DMA_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3E8'}), (b {id: 'LOG_MSG_0001'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3E9'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3E9'}), (b {id: 'LOG_MSG_0091'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3E9'}), (b {id: 'ZigBee_Request_Retransmission_22'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3EA'}), (b {id: 'FFT_Engine'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3EA'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3EB'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3EC'}), (b {id: 'CRC_Checker'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3ED'}), (b {id: 'DMA_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3ED'}), (b {id: 'LOG_MSG_0078'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3ED'}), (b {id: '5G_NR_Lower_MCS_20'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3EE'}), (b {id: 'RF_FrontEnd'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3EF'}), (b {id: 'Decoder'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3EF'}), (b {id: 'LTE_Lower_MCS_50'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3EF'}), (b {id: 'LOG_MSG_0177'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F0'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F1'}), (b {id: 'Scheduler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F1'}), (b {id: 'ModeSwitch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F2'}), (b {id: 'FFT_Engine'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F3'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F3'}), (b {id: 'WiFi_6_Request_Retransmission_12'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F4'}), (b {id: 'Decoder'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F5'}), (b {id: 'L1_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F5'}), (b {id: 'LOG_MSG_0014'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F6'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F6'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F7'}), (b {id: 'Demodulator'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F8'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F8'}), (b {id: 'LOG_MSG_0189'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3F9'}), (b {id: 'DMA_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3F9'}), (b {id: 'LOG_MSG_0097'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3FA'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3FB'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3FB'}), (b {id: 'LOG_MSG_0025'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x3FC'}), (b {id: 'Demodulator'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3FD'}), (b {id: 'Sync_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3FE'}), (b {id: 'RF_FrontEnd'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x3FF'}), (b {id: 'CRC_Checker'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x400'}), (b {id: 'Decoder'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x400'}), (b {id: 'LOG_MSG_0003'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x401'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x402'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x403'}), (b {id: 'Scheduler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x404'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x405'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x406'}), (b {id: 'Sync_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x407'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x408'}), (b {id: 'DMA_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x408'}), (b {id: 'LOG_MSG_0062'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x409'}), (b {id: 'Beam_Forming_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40A'}), (b {id: 'DMA_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40A'}), (b {id: 'LOG_MSG_0192'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x40B'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40B'}), (b {id: 'REG_0x407'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x40C'}), (b {id: 'Scheduler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40C'}), (b {id: 'LOG_MSG_0119'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x40D'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40D'}), (b {id: 'LOG_MSG_0190'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x40E'}), (b {id: 'Demodulator'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40F'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x40F'}), (b {id: 'LOG_MSG_0066'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x40F'}), (b {id: 'LOG_MSG_0180'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x410'}), (b {id: 'FFT_Engine'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x411'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x412'}), (b {id: 'Beam_Forming_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x412'}), (b {id: 'REG_0x3F0'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x412'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x413'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x414'}), (b {id: 'L1_Controller'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x414'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x415'}), (b {id: 'Scrambler'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x415'}), (b {id: 'LOG_MSG_0028'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x416'}), (b {id: 'Beam_Forming_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x417'}), (b {id: 'Interleaver'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x418'}), (b {id: 'Sync_Unit'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x418'}), (b {id: 'LOG_MSG_0017'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x418'}), (b {id: 'NB-IoT'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'REG_0x419'}), (b {id: 'Interleaver'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'REG_0x419'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_PSS_Miss'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Adjust_Sync_Threshold_55'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_SSS_Detection_Fail'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Reset_Sync_State_76'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_CFO_Drift'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Widen_Search_Window_93'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Widen_Search_Window_93'}), (b {id: '5G_NR_Adjust_Sync_Threshold_56'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Timing_Offset'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Widen_Search_Window_51'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Frame_Sync_Lost'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Frame_Sync_Lost'}), (b {id: 'LOG_MSG_0065'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Frame_Sync_Lost'}), (b {id: 'LOG_MSG_0191'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Frame_Sync_Lost'}), (b {id: 'REG_0x40B'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Reset_Sync_State_73'}), (b {id: 'LTE_Frame_Sync_Lost'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Symbol_Boundary_Error'}), (b {id: 'LTE'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'LTE_Symbol_Boundary_Error'}), (b {id: 'REG_0x409'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Switch_Beam_87'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_PSS_Miss'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Widen_Search_Window_76'}), (b {id: '5G_NR_PSS_Miss'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Widen_Search_Window_76'}), (b {id: 'LOG_MSG_0103'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_SSS_Detection_Fail'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Adjust_Sync_Threshold_76'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Adjust_Sync_Threshold_76'}), (b {id: 'NB-IoT_PSS_Miss'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_CFO_Drift'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Adjust_Sync_Threshold_56'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Adjust_Sync_Threshold_56'}), (b {id: 'NB-IoT_Request_Retransmission_21'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Adjust_Sync_Threshold_56'}), (b {id: 'ZigBee_Enable_Diversity_43'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Timing_Offset'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Timing_Offset'}), (b {id: 'LOG_MSG_0068'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Reset_Sync_State_66'}), (b {id: '5G_NR_Timing_Offset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Reset_Sync_State_66'}), (b {id: 'LOG_MSG_0007'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Frame_Sync_Lost'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Reset_Sync_State_18'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Symbol_Boundary_Error'}), (b {id: '5G_NR'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: '5G_NR_Switch_Beam_50'}), (b {id: '5G_NR_Symbol_Boundary_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Switch_Beam_50'}), (b {id: 'LOG_MSG_0155'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_PSS_Miss'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_76'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_76'}), (b {id: 'LOG_MSG_0126'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_76'}), (b {id: 'LOG_MSG_0139'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_76'}), (b {id: 'LOG_MSG_0110'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_76'}), (b {id: 'ZigBee_Reset_Sync_State_100'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_SSS_Detection_Fail'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_SSS_Detection_Fail'}), (b {id: 'WiFi_6_Widen_Search_Window_88'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Adjust_Sync_Threshold_26'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Adjust_Sync_Threshold_26'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_CFO_Drift'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_CFO_Drift'}), (b {id: 'LOG_MSG_0104'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Reset_Sync_State_12'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Reset_Sync_State_12'}), (b {id: 'Multi_Path_Fading'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Reset_Sync_State_12'}), (b {id: 'REG_0x412'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Timing_Offset'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_13'}), (b {id: 'WiFi_6_Timing_Offset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Frame_Sync_Lost'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_88'}), (b {id: 'WiFi_6_Frame_Sync_Lost'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Widen_Search_Window_88'}), (b {id: 'Retry_Limit'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Symbol_Boundary_Error'}), (b {id: 'WiFi_6'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'WiFi_6_Symbol_Boundary_Error'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Symbol_Boundary_Error'}), (b {id: 'NB-IoT_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Adjust_Sync_Threshold_57'}), (b {id: 'WiFi_6_Symbol_Boundary_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_PSS_Miss'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_PSS_Miss'}), (b {id: 'Retry_Limit'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Switch_Beam_43'}), (b {id: 'NB-IoT_PSS_Miss'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_SSS_Detection_Fail'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_SSS_Detection_Fail'}), (b {id: 'ZigBee_Reset_Sync_State_100'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_SSS_Detection_Fail'}), (b {id: 'LOG_MSG_0104'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Reset_Sync_State_8'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Reset_Sync_State_8'}), (b {id: 'Watchdog_Reset'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_CFO_Drift'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_CFO_Drift'}), (b {id: 'LOG_MSG_0050'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_CFO_Drift'}), (b {id: 'REG_0x3F2'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Widen_Search_Window_44'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Timing_Offset'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_Switch_Beam_35'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Switch_Beam_35'}), (b {id: 'Temperature_High'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Frame_Sync_Lost'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_Reset_Sync_State_40'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Reset_Sync_State_40'}), (b {id: 'ZigBee_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Symbol_Boundary_Error'}), (b {id: 'NB-IoT'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'NB-IoT_Enable_Freq_Tracking_3'}), (b {id: 'NB-IoT_Symbol_Boundary_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Enable_Freq_Tracking_3'}), (b {id: 'LOG_MSG_0044'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Enable_Freq_Tracking_3'}), (b {id: 'LOG_MSG_0036'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_PSS_Miss'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_PSS_Miss'}), (b {id: 'ZigBee_Soft_Reset_Rx_74'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Switch_Beam_25'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Switch_Beam_25'}), (b {id: 'LOG_MSG_0042'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Switch_Beam_25'}), (b {id: 'LOG_MSG_0050'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_SSS_Detection_Fail'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_SSS_Detection_Fail'}), (b {id: 'LOG_MSG_0102'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Enable_Freq_Tracking_3'}), (b {id: 'ZigBee_SSS_Detection_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Enable_Freq_Tracking_3'}), (b {id: 'LOG_MSG_0045'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Enable_Freq_Tracking_3'}), (b {id: 'LTE_Adjust_Sync_Threshold_55'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_CFO_Drift'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_CFO_Drift'}), (b {id: 'ZigBee_Reset_Sync_State_100'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Enable_Freq_Tracking_84'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Enable_Freq_Tracking_84'}), (b {id: 'LOG_MSG_0044'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Timing_Offset'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_Widen_Search_Window_39'}), (b {id: 'ZigBee_Timing_Offset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Widen_Search_Window_39'}), (b {id: 'LOG_MSG_0111'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Frame_Sync_Lost'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_Reset_Sync_State_100'}), (b {id: 'ZigBee_Frame_Sync_Lost'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Reset_Sync_State_100'}), (b {id: 'REG_0x413'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Symbol_Boundary_Error'}), (b {id: 'ZigBee'})
MERGE (a)-[:RELATED_TO]->(b);
MATCH (a {id: 'ZigBee_Adjust_Sync_Threshold_70'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Adjust_Sync_Threshold_70'}), (b {id: 'LOG_MSG_0063'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Constellation_Mismatch'}), (b {id: 'REG_0x404'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Request_Retransmission_8'}), (b {id: 'LTE_Constellation_Mismatch'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Request_Retransmission_8'}), (b {id: 'REG_0x412'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Request_Retransmission_99'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Request_Retransmission_99'}), (b {id: 'LOG_MSG_0193'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_LDPC_Decode_Fail'}), (b {id: 'LOG_MSG_0107'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Enable_Diversity_72'}), (b {id: 'LTE_LDPC_Decode_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Enable_Diversity_72'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Enable_Diversity_36'}), (b {id: 'LTE_CRC_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_Enable_Diversity_36'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Lower_MCS_72'}), (b {id: 'LTE_Polar_Code_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LTE_QAM_Demap_Error'}), (b {id: 'LOG_MSG_0188'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LTE_Lower_MCS_50'}), (b {id: 'LTE_QAM_Demap_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Constellation_Mismatch'}), (b {id: 'LTE_Switch_Beam_87'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Constellation_Mismatch'}), (b {id: 'LOG_MSG_0015'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Increase_Power_50'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_EVM_High'}), (b {id: 'Low_SNR'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Increase_Power_59'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Request_Retransmission_11'}), (b {id: '5G_NR_LDPC_Decode_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Request_Retransmission_11'}), (b {id: 'REG_0x414'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Lower_MCS_20'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Lower_MCS_20'}), (b {id: 'LOG_MSG_0011'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Lower_MCS_20'}), (b {id: 'LOG_MSG_0166'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Lower_MCS_20'}), (b {id: 'LOG_MSG_0030'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Polar_Code_Fail'}), (b {id: 'LOG_MSG_0005'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Request_Retransmission_87'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: '5G_NR_Request_Retransmission_87'}), (b {id: 'LOG_MSG_0060'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: '5G_NR_Soft_Reset_Rx_65'}), (b {id: '5G_NR_QAM_Demap_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Constellation_Mismatch'}), (b {id: 'LTE_Polar_Code_Fail'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Increase_Power_7'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Request_Retransmission_12'}), (b {id: 'WiFi_6_EVM_High'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Request_Retransmission_12'}), (b {id: 'LOG_MSG_0010'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_LDPC_Decode_Fail'}), (b {id: 'ZigBee_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Enable_Diversity_47'}), (b {id: 'WiFi_6_LDPC_Decode_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Enable_Diversity_47'}), (b {id: 'LOG_MSG_0190'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'WiFi_6_Increase_Power_63'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Request_Retransmission_55'}), (b {id: 'WiFi_6_Polar_Code_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Enable_Diversity_13'}), (b {id: 'WiFi_6_QAM_Demap_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'WiFi_6_Enable_Diversity_13'}), (b {id: '5G_NR_Request_Retransmission_11'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_15'}), (b {id: 'NB-IoT_Constellation_Mismatch'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_15'}), (b {id: 'ZigBee_Reset_Sync_State_100'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_15'}), (b {id: 'LOG_MSG_0041'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_EVM_High'}), (b {id: 'Channel_Congestion'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_EVM_High'}), (b {id: 'L1_Controller'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Enable_Diversity_93'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Enable_Diversity_93'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_LDPC_Decode_Fail'}), (b {id: 'LTE_Widen_Search_Window_51'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Enable_Diversity_51'}), (b {id: 'NB-IoT_LDPC_Decode_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Enable_Diversity_51'}), (b {id: 'LOG_MSG_0082'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_CRC_Error'}), (b {id: 'REG_0x3F2'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_16'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_16'}), (b {id: 'LOG_MSG_0070'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'NB-IoT_Increase_Power_24'}), (b {id: 'NB-IoT_Polar_Code_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'NB-IoT_Request_Retransmission_21'}), (b {id: 'NB-IoT_QAM_Demap_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Constellation_Mismatch'}), (b {id: 'LOG_MSG_0152'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Increase_Power_12'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Request_Retransmission_62'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Request_Retransmission_62'}), (b {id: 'LOG_MSG_0181'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Request_Retransmission_62'}), (b {id: 'Scrambler'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_LDPC_Decode_Fail'}), (b {id: 'Scheduler'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Soft_Reset_Rx_74'}), (b {id: 'ZigBee_LDPC_Decode_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Soft_Reset_Rx_74'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Enable_Diversity_43'}), (b {id: 'ZigBee_CRC_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Polar_Code_Fail'}), (b {id: 'LOG_MSG_0125'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Request_Retransmission_22'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_QAM_Demap_Error'}), (b {id: 'LOG_MSG_0043'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ZigBee_Enable_Diversity_88'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'ZigBee_Enable_Diversity_88'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Context_Switch_Timeout'}), (b {id: 'LOG_MSG_0000'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Force_Unlock_84'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Force_Unlock_84'}), (b {id: 'LOG_MSG_0036'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'Watchdog_Reset'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'Memory_Parity_Error'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'AXI_Bus_Lockup'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:CAN_TRIGGER]->(b);
MATCH (a {id: 'ModeSwitch'}), (b {id: 'LOG_MSG_0010'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Shadow_Reg_Update_Fail'}), (b {id: 'REG_0x405'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Shadow_Reg_Update_Fail'}), (b {id: 'RF_FrontEnd'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Shadow_Reg_Update_Fail'}), (b {id: 'REG_0x40B'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Clear_Shadow_Buffer_94'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Clear_Shadow_Buffer_94'}), (b {id: 'LOG_MSG_0135'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'DMA_Bus_Hang'}), (b {id: 'LOG_MSG_0036'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Flush_Pipeline_34'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Flush_Pipeline_34'}), (b {id: 'NB-IoT_Enable_Diversity_51'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Flush_Pipeline_34'}), (b {id: 'Rate_Matcher'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Force_Unlock_68'}), (b {id: 'Watchdog_Reset'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Flush_Pipeline_48'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'Memory_Parity_Error'}), (b {id: 'LOG_MSG_0126'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Memory_Parity_Error'}), (b {id: '5G_NR_Request_Retransmission_11'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Clear_Shadow_Buffer_17'}), (b {id: 'Memory_Parity_Error'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Clear_Shadow_Buffer_56'}), (b {id: 'AXI_Bus_Lockup'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'SOL_Clear_Shadow_Buffer_56'}), (b {id: 'LOG_MSG_0140'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'FIFO_Underrun'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'FIFO_Underrun'}), (b {id: 'LOG_MSG_0167'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SOL_Reset_CGRA_Tile_40'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:FIXES]->(b);
MATCH (a {id: 'LOG_MSG_0000'}), (b {id: 'ZigBee_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0001'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0002'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0002'}), (b {id: 'LOG_MSG_0129'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0003'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0003'}), (b {id: 'LOG_MSG_0059'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0004'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0005'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0005'}), (b {id: 'LOG_MSG_0153'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0006'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0006'}), (b {id: 'NB-IoT_Enable_Diversity_51'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0007'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0007'}), (b {id: 'REG_0x404'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0007'}), (b {id: 'Scheduler'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0007'}), (b {id: 'LTE_QAM_Demap_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0008'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0009'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0009'}), (b {id: 'LOG_MSG_0190'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0010'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0011'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0011'}), (b {id: 'LOG_MSG_0148'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0011'}), (b {id: 'LOG_MSG_0191'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0011'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0012'}), (b {id: 'LTE_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0013'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0013'}), (b {id: 'REG_0x40F'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0014'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0015'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0015'}), (b {id: 'LOG_MSG_0107'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0016'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0017'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0018'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0018'}), (b {id: 'LOG_MSG_0048'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0019'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0020'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0021'}), (b {id: 'WiFi_6_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0022'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0022'}), (b {id: '5G_NR_Switch_Beam_50'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0022'}), (b {id: 'LOG_MSG_0041'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0023'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0023'}), (b {id: 'LTE_Enable_Diversity_36'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0024'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0024'}), (b {id: 'LOG_MSG_0112'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0025'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0026'}), (b {id: 'LTE_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0027'}), (b {id: 'LTE_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0028'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0028'}), (b {id: 'LOG_MSG_0089'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0029'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0029'}), (b {id: 'NB-IoT_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0029'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0030'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0031'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0032'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0032'}), (b {id: 'LOG_MSG_0075'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0032'}), (b {id: 'LTE_Switch_Beam_87'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0033'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0034'}), (b {id: 'WiFi_6_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0035'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0035'}), (b {id: '5G_NR_Reset_Sync_State_18'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0036'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0036'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0036'}), (b {id: 'REG_0x3F5'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0037'}), (b {id: 'WiFi_6_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0037'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0038'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0038'}), (b {id: 'REG_0x40E'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0039'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0040'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0040'}), (b {id: 'Neighbor_Cell_Interference'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0041'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0041'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0042'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0042'}), (b {id: 'LOG_MSG_0135'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0043'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0043'}), (b {id: 'LOG_MSG_0104'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0043'}), (b {id: 'NB-IoT_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0044'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0045'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0045'}), (b {id: 'LOG_MSG_0199'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0045'}), (b {id: 'LOG_MSG_0113'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0046'}), (b {id: 'LTE_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0046'}), (b {id: 'ZigBee_Soft_Reset_Rx_74'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0046'}), (b {id: 'Low_SNR'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0047'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0047'}), (b {id: 'LOG_MSG_0167'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0047'}), (b {id: '5G_NR_Adjust_Sync_Threshold_76'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0048'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0048'}), (b {id: 'Modulation_Order'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0048'}), (b {id: 'High_Doppler'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0049'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0050'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0050'}), (b {id: 'L1_Controller'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0051'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0052'}), (b {id: 'ZigBee_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0053'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0053'}), (b {id: 'LOG_MSG_0144'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0054'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0054'}), (b {id: 'LOG_MSG_0089'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0055'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0056'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0056'}), (b {id: 'ZigBee_Request_Retransmission_62'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0057'}), (b {id: 'ZigBee_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0058'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0059'}), (b {id: 'AXI_Bus_Lockup'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0059'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0059'}), (b {id: 'LOG_MSG_0017'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0060'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0061'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0061'}), (b {id: 'LOG_MSG_0158'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0062'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0062'}), (b {id: 'LOG_MSG_0155'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0063'}), (b {id: '5G_NR_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0064'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0064'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0065'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0066'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0066'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0066'}), (b {id: 'REG_0x3E9'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0067'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0067'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0068'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0069'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0069'}), (b {id: 'LOG_MSG_0091'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0070'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0070'}), (b {id: 'LOG_MSG_0059'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0071'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0071'}), (b {id: 'LOG_MSG_0118'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0072'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0072'}), (b {id: 'ZigBee_Request_Retransmission_22'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0072'}), (b {id: '5G_NR_Reset_Sync_State_18'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0073'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0073'}), (b {id: 'Shadowing'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0073'}), (b {id: 'LOG_MSG_0087'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0074'}), (b {id: 'WiFi_6_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0075'}), (b {id: 'NB-IoT_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0076'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0076'}), (b {id: 'LOG_MSG_0059'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0076'}), (b {id: 'LOG_MSG_0116'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0077'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0077'}), (b {id: 'WiFi_6_Increase_Power_7'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0077'}), (b {id: 'REG_0x3EE'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0078'}), (b {id: 'WiFi_6_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0078'}), (b {id: 'LOG_MSG_0100'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0079'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0080'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0081'}), (b {id: 'WiFi_6_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0082'}), (b {id: '5G_NR_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0082'}), (b {id: 'LOG_MSG_0060'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0082'}), (b {id: 'REG_0x413'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0083'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0083'}), (b {id: 'LOG_MSG_0077'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0083'}), (b {id: 'WiFi_6_Increase_Power_7'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0084'}), (b {id: '5G_NR_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0084'}), (b {id: 'LOG_MSG_0159'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0085'}), (b {id: 'ZigBee_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0086'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0087'}), (b {id: 'NB-IoT_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0088'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0089'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0090'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0090'}), (b {id: 'LTE_Adjust_Sync_Threshold_55'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0091'}), (b {id: 'WiFi_6_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0091'}), (b {id: 'REG_0x412'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0091'}), (b {id: 'LOG_MSG_0141'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0092'}), (b {id: 'WiFi_6_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0093'}), (b {id: '5G_NR_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0094'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0094'}), (b {id: 'SOL_Clear_Shadow_Buffer_94'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0094'}), (b {id: 'LOG_MSG_0019'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0094'}), (b {id: 'Memory_Parity_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0095'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0095'}), (b {id: 'NB-IoT_Polar_Code_Fail'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0096'}), (b {id: 'NB-IoT_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0096'}), (b {id: 'Coding_Rate'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0097'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0097'}), (b {id: 'LOG_MSG_0085'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0098'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0099'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0100'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0101'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0102'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0103'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0103'}), (b {id: '5G_NR_Increase_Power_50'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0104'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0105'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0105'}), (b {id: 'LOG_MSG_0197'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0105'}), (b {id: 'NB-IoT_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0105'}), (b {id: 'LOG_MSG_0151'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0106'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0107'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0108'}), (b {id: '5G_NR_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0109'}), (b {id: 'Memory_Parity_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0110'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0111'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0111'}), (b {id: 'LOG_MSG_0119'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0112'}), (b {id: 'ZigBee_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0113'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0113'}), (b {id: 'LOG_MSG_0043'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0114'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0114'}), (b {id: 'LOG_MSG_0098'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0114'}), (b {id: 'LOG_MSG_0044'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0115'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0116'}), (b {id: 'ZigBee_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0117'}), (b {id: 'LTE_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0117'}), (b {id: 'REG_0x416'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0118'}), (b {id: '5G_NR_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0118'}), (b {id: '5G_NR_Request_Retransmission_11'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0119'}), (b {id: 'WiFi_6_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0119'}), (b {id: 'REG_0x3FD'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0119'}), (b {id: 'WiFi_6_Widen_Search_Window_88'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0120'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0121'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0122'}), (b {id: 'WiFi_6_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0123'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0123'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0124'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0125'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0126'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0127'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0128'}), (b {id: 'NB-IoT_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0129'}), (b {id: 'NB-IoT_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0129'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0129'}), (b {id: 'LTE_EVM_High'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0130'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0130'}), (b {id: 'LOG_MSG_0040'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0131'}), (b {id: 'LTE_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0132'}), (b {id: 'NB-IoT_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0132'}), (b {id: 'LOG_MSG_0020'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0133'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0134'}), (b {id: 'LTE_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0134'}), (b {id: 'LOG_MSG_0030'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0134'}), (b {id: 'LOG_MSG_0175'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0135'}), (b {id: 'WiFi_6_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0135'}), (b {id: 'ZigBee_Switch_Beam_25'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0136'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0136'}), (b {id: 'LOG_MSG_0068'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0137'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0137'}), (b {id: 'LOG_MSG_0096'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0137'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0137'}), (b {id: 'LOG_MSG_0038'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0138'}), (b {id: 'DMA_Bus_Hang'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0138'}), (b {id: 'REG_0x40E'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0139'}), (b {id: '5G_NR_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0140'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0141'}), (b {id: 'ZigBee_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0142'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0142'}), (b {id: 'LTE_Reset_Sync_State_73'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0143'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0143'}), (b {id: 'LOG_MSG_0163'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0143'}), (b {id: 'LOG_MSG_0083'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0144'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0145'}), (b {id: 'LTE_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0145'}), (b {id: 'LOG_MSG_0005'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0146'}), (b {id: 'LTE_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0146'}), (b {id: 'LTE_Adjust_Sync_Threshold_55'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0147'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0148'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0148'}), (b {id: 'LOG_MSG_0167'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0149'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0149'}), (b {id: 'LOG_MSG_0107'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0149'}), (b {id: 'LOG_MSG_0085'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0150'}), (b {id: 'FIFO_Underrun'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0150'}), (b {id: 'ZigBee_Enable_Freq_Tracking_3'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0150'}), (b {id: 'LOG_MSG_0126'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0151'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0151'}), (b {id: 'L1_Controller'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0152'}), (b {id: 'LTE_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0152'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0153'}), (b {id: 'NB-IoT_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0153'}), (b {id: 'LOG_MSG_0079'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0154'}), (b {id: 'WiFi_6_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0154'}), (b {id: 'ZigBee_Enable_Diversity_88'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0154'}), (b {id: 'REG_0x3F1'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0155'}), (b {id: 'LTE_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0156'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0156'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0156'}), (b {id: 'LOG_MSG_0176'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0157'}), (b {id: '5G_NR_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0157'}), (b {id: 'LOG_MSG_0178'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0158'}), (b {id: 'ZigBee_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0158'}), (b {id: 'LOG_MSG_0135'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0158'}), (b {id: 'NB-IoT_Enable_Diversity_93'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0159'}), (b {id: 'LTE_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0159'}), (b {id: 'LOG_MSG_0087'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0160'}), (b {id: '5G_NR_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0161'}), (b {id: 'ZigBee_EVM_High'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0162'}), (b {id: 'ZigBee_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0162'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0162'}), (b {id: 'REG_0x409'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0163'}), (b {id: '5G_NR_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0163'}), (b {id: 'LOG_MSG_0105'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0164'}), (b {id: 'WiFi_6_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0165'}), (b {id: 'Context_Switch_Timeout'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0166'}), (b {id: 'NB-IoT_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0167'}), (b {id: 'WiFi_6_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0168'}), (b {id: '5G_NR_Frame_Sync_Lost'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0169'}), (b {id: 'LTE_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0170'}), (b {id: 'WiFi_6_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0170'}), (b {id: 'AXI_Bus_Lockup'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0171'}), (b {id: 'Shadow_Reg_Update_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0171'}), (b {id: 'LOG_MSG_0118'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0172'}), (b {id: 'ZigBee_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0172'}), (b {id: 'LTE_Widen_Search_Window_93'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0173'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0174'}), (b {id: 'NB-IoT_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0174'}), (b {id: 'LOG_MSG_0196'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0174'}), (b {id: 'Clock_Jitter'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0175'}), (b {id: 'WiFi_6_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0175'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0176'}), (b {id: '5G_NR_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0177'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0178'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0178'}), (b {id: 'ZigBee_Adjust_Sync_Threshold_70'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0178'}), (b {id: 'REG_0x416'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0179'}), (b {id: 'NB-IoT_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0179'}), (b {id: 'LTE_Frame_Sync_Lost'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0180'}), (b {id: 'WiFi_6_PSS_Miss'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0180'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0181'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0181'}), (b {id: 'Buffer_Overflow'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0182'}), (b {id: 'Instruction_Fetch_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0182'}), (b {id: 'REG_0x405'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0182'}), (b {id: 'LOG_MSG_0186'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0183'}), (b {id: 'NB-IoT_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0183'}), (b {id: '5G_NR_Reset_Sync_State_18'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0184'}), (b {id: 'ZigBee_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0185'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0185'}), (b {id: 'REG_0x3E9'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0186'}), (b {id: 'NB-IoT_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0187'}), (b {id: 'WiFi_6_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0187'}), (b {id: 'Packet_Loss_Burst'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0188'}), (b {id: 'LTE_QAM_Demap_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0189'}), (b {id: 'LTE_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0190'}), (b {id: 'ZigBee_Constellation_Mismatch'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0190'}), (b {id: 'WiFi_6_Enable_Diversity_47'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0190'}), (b {id: 'Neighbor_Cell_Interference'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0191'}), (b {id: '5G_NR_SSS_Detection_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0192'}), (b {id: 'ZigBee_Polar_Code_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0193'}), (b {id: '5G_NR_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0193'}), (b {id: 'Voltage_Drop'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0194'}), (b {id: '5G_NR_Symbol_Boundary_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0195'}), (b {id: 'LTE_LDPC_Decode_Fail'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0195'}), (b {id: 'SOL_Clear_Shadow_Buffer_17'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0196'}), (b {id: 'WiFi_6_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0196'}), (b {id: 'LOG_MSG_0049'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0197'}), (b {id: 'NB-IoT_CRC_Error'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0197'}), (b {id: 'LOG_MSG_0128'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'LOG_MSG_0198'}), (b {id: '5G_NR_CFO_Drift'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0199'}), (b {id: 'NB-IoT_Timing_Offset'})
MERGE (a)-[:INDICATES]->(b);
MATCH (a {id: 'LOG_MSG_0199'}), (b {id: 'LOG_MSG_0126'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SNR_Threshold'}), (b {id: 'CRC_Checker'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'SNR_Threshold'}), (b {id: 'LOG_MSG_0041'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SNR_Threshold'}), (b {id: 'MAC_Filter'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'SNR_Threshold'}), (b {id: 'REG_0x411'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Retry_Limit'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'Beam_Index'}), (b {id: 'RF_FrontEnd'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'Subcarrier_Spacing'}), (b {id: 'RF_FrontEnd'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'Subcarrier_Spacing'}), (b {id: 'REG_0x416'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Coding_Rate'}), (b {id: 'RRC_Manager'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'Modulation_Order'}), (b {id: 'Decoder'})
MERGE (a)-[:CONFIGURES]->(b);
MATCH (a {id: 'Modulation_Order'}), (b {id: 'WiFi_6_Request_Retransmission_12'})
MERGE (a)-[:CORRELATED_WITH]->(b);
MATCH (a {id: 'Modulation_Order'}), (b {id: 'LOG_MSG_0091'})
MERGE (a)-[:CORRELATED_WITH]->(b);