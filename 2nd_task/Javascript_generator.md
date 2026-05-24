## This is the JAVAScript Generator code : 
```
javascript.javascriptGenerator.forBlock['open_gate_with_speed'] = function(block, generator) {

  var speed = block.getFieldValue('SPEED');

  var delayTime =
```

## this is the block defination:

```
Blockly.Blocks['open_gate_with_speed'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("open gate with speed")
        .appendField(new Blockly.FieldNumber(5, -10, 10, 1), "SPEED");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
  }
};
```
