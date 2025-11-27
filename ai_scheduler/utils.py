def print_gantt_chart(schedule_log):
    """
    Prints a text-based Gantt chart.
    """
    print("\n" + "="*60)
    print("               AI GENERATED SCHEDULE (GANTT)               ")
    print("="*60)
    
    # Sort by resource
    resources = sorted(list(set(item['resource'] for item in schedule_log)))
    
    # Find max time
    max_time = max(item['end'] for item in schedule_log)
    scale = 1
    if max_time > 100:
        scale = max_time / 100.0 # Scale to fit ~100 chars
    
    print(f"Total Cycles: {max_time}")
    print(f"Scale: 1 char ~= {scale:.1f} cycles")
    print("-" * 120)

    for res in resources:
        # Build the timeline string
        timeline = [" "] * 100
        res_tasks = [t for t in schedule_log if t['resource'] == res]
        
        for t in res_tasks:
            start_idx = int(t['start'] / scale)
            end_idx = int(t['end'] / scale)
            length = max(1, end_idx - start_idx)
            
            # Create a label (e.g., "Sync_Ant0")
            label = t['name']
            # Truncate if too long for the block
            if len(label) > length:
                label = label[:length]
            
            # Fill timeline
            for i in range(length):
                if start_idx + i < 100:
                    char_to_print = "#"
                    if i < len(label):
                        char_to_print = label[i]
                    timeline[start_idx + i] = char_to_print
        
        timeline_str = "".join(timeline)
        print(f"{res:<15} | {timeline_str}")
    
    print("-" * 120)
