## This is the JAVAScript Generator code : 
```
javascript.javascriptGenerator.forBlock['open_gate_with_speed'] = function(block, generator) {

  var speed = block.getFieldValue('SPEED');

  var delayTime = 110 - (speed * 10);

  var code = `
for (let pos = 0; pos <= 90; pos++) {
  servo.write(pos);
  delay(${delayTime});
}
`;

  return code;
};
```
## this is JSON block defination :

```
{
  "type": "open_gate_with_speed",
  "message0": "Open Gate with speed %1",
  "args0": [
    {
      "type": "field_number",
      "name": "SPEED",
      "value": 5,
      "min": 1,
      "max": 10
    }
  ],
  "previousStatement": null,
  "nextStatement": null,
  "colour": 230,
  "tooltip": "",
  "helpUrl": ""
}
```
## this is the block defination in Javascript :

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
