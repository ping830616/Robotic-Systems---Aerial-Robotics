
%% Example 1
% all signals have time ranging from 0 to 1
% we have 2 groups of data
% each group has 3 signals
b = signalbuilder([], 'create', [0 1], ...
    {[0 0],[1 1];[1 0],[0 1];[1 1],[0 0]}, ...
    {'sigA','sigB','sigC'}, {'groupA','groupB'});

%% Example 2
% we have 2 groups of data
% each group has 3 signals
% each signal group has it's own time range
block = signalbuilder(b, 'append', {[0 1], [0 10]}, ...
    {[0 0],[1 1];[1 0],[0 1];[1 1],[0 0]}, ...
    {'sigA','sigB','sigC'}, {'groupC','groupD'});
